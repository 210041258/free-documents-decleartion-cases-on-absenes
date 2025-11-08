-- I CREATE THE FUNCTIONS AND PROCEDURES
SET SERVEROUTPUT ON

-------------------------PROCEDURES---SIDE--------------------------
-- START TASK 1 :
CREATE OR REPLACE PROCEDURE CAL_TIME_MOVIE(_MOV_TITLE IN VARCHAR2, _PLAY_TIME_MOV_ OUT VARCHAR2) AS
    VAR_MOV_TIME NUMBER;
BEGIN

    SELECT MOV_TIME INTO VAR_MOV_TIME
    FROM MOVIE
    WHERE MOV_TITLE = _MOV_TITLE;

    IF VAR_MOV_TIME > 30 THEN
        _PLAY_TIME_MOV_ := TO_CHAR(TRUNC((VAR_MOV_TIME + ((VAR_MOV_TIME - 30) / 70) * 15) / 60)) || 'Hours' ||
                           TO_CHAR(MOD(((VAR_MOV_TIME + ((VAR_MOV_TIME - 30) / 70) * 15), 60))) || 'Minutes';
    ELSE
        _PLAY_TIME_MOV_ := TO_CHAR(TRUNC(VAR_MOV_TIME / 60)) || 'Hours' || TO_CHAR(MOD(VAR_MOV_TIME, 60)) || 'Minutes';
    END IF;

END;
/

-- END TASK 1;

-- START TASK 2:
CREATE OR REPLACE PROCEDURE FIND_N(_N_ IN NUMBER, _MOV_TITLE_ OUT VARCHAR2) AS
BEGIN
    FOR MOVIE_REC IN (
        SELECT MOV_TITLE
        FROM (
            SELECT m.MOV_TITLE, AVG(R.REV_STARS) AS avg_stars
            FROM MOVIE m
            JOIN RATING R ON m.MOV_ID = R.MOV_ID
            GROUP BY m.MOV_TITLE
            ORDER BY avg_stars DESC
        )
        WHERE ROWNUM <= _N_
    ) LOOP
        _MOV_TITLE_ := MOVIE_REC.MOV_TITLE;
    END LOOP;
END;
/
-- END TASK 2;

-------------------------FUNCTIONS---SIDE--------------------------

-- START TASK 3:
CREATE OR REPLACE FUNCTION EARNING(_MOV_ID IN NUMBER) RETURN NUMBER AS
    _TOTAL_EARNING NUMBER := 0;
    _RELEASE_YEAR NUMBER;
    _CURRENT_YEAR NUMBER := EXTRACT(YEAR FROM SYSDATE);
BEGIN
    SELECT EXTRACT(YEAR FROM MOV_RELEASEDATE) INTO _RELEASE_YEAR
    WHERE MOV_ID = _MOV_ID;

    FOR REV_EARNING_REC IN (SELECT R.REV_STARS FROM RATING R WHERE R.MOV_ID = _MOV_ID) LOOP
        IF REV_EARNING_REC.REV_STARS >= 6 AND _CURRENT_YEAR = _RELEASE_YEAR THEN
            _TOTAL_EARNING := _TOTAL_EARNING + 10;
        END IF;
    END LOOP;

    RETURN _TOTAL_EARNING / (_CURRENT_YEAR - _RELEASE_YEAR);
END;
/
-- END TASK 3;

-- START TASK 4:
CREATE OR REPLACE FUNCTION genre_info(GEN_ID IN NUMBER) RETURN VARCHAR2 AS
    _genre_status VARCHAR2(20);
BEGIN
    FOR genre_status_rec IN (
        SELECT COUNT(*) AS count_reviews, AVG(R.REV_STARS) AS avg_stars
        FROM MOVIE M
        JOIN RATING R ON R.MOV_ID = M.MOV_ID
    ) LOOP
        IF genre_status_rec.count_reviews > (SELECT AVG(review_count) FROM Genre_Stats) AND
           genre_status_rec.avg_stars < (SELECT AVG(avg_rating) FROM Genre_Stats) THEN
            _genre_status := 'Widely Watched';
        ELSIF genre_status_rec.count_reviews < (SELECT AVG(review_count) FROM Genre_Stats) AND
              genre_status_rec.avg_stars > (SELECT AVG(avg_rating) FROM Genre_Stats) THEN
            _genre_status := 'Highly Rated';
        ELSIF genre_status_rec.count_reviews > (SELECT AVG(review_count) FROM Genre_Stats) AND
              genre_status_rec.avg_stars > (SELECT AVG(avg_rating) FROM Genre_Stats) THEN
            _genre_status := 'People’s Favorite';
        ELSE
            _genre_status := 'SO SO';
        END IF;
    END LOOP;

    RETURN _genre_status;
END;
/
-- END TASK 4;

-- START TASK 5:
CREATE OR REPLACE FUNCTION MOST_FREQUENCY_MOV(_START_DATE IN DATE, _FINISH_DATE OUT DATE) RETURN VARCHAR2 AS
    _genre_name GENRES.GEN_TITLE%TYPE;
BEGIN
    FOR FREQ_MOV IN (
        SELECT g.GEN_TITLE
        FROM MOVIE M
        JOIN MTYPE MT ON M.MOV_ID = MT.MOV_ID
        JOIN GENRES G ON MT.GEN_ID = G.GEN_ID
        WHERE M.MOV_RELEASEDATE BETWEEN _START_DATE AND _FINISH_DATE
        GROUP BY g.GEN_TITLE
        ORDER BY COUNT(*) DESC
    ) LOOP
        _genre_name := FREQ_MOV.GEN_TITLE;
        EXIT;
    END LOOP;

    RETURN _genre_name;
END;
/
-- END TASK 5;
