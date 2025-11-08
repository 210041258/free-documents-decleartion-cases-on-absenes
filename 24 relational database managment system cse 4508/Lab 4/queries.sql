CREATE TABLE bus (
    bus_id INT PRIMARY KEY,
    bus_model VARCHAR(50),
    manufacturer VARCHAR(50)
);

CREATE TABLE driver (
    driver_id INT PRIMARY KEY,
    driver_name VARCHAR(100)
);

CREATE TABLE depot (
    depot_id INT PRIMARY KEY,
    depot_name VARCHAR(100),
    city VARCHAR(100)
);

CREATE TABLE trip (
    trip_id INT PRIMARY KEY,
    segment_id INT,
    bus_id INT,
    driver_id INT,
    depot_id INT,
    trip_date DATE,
    kilometers_traveled INT,
    fuel_consumption INT,
    passengers_count INT,
    trip_duration INT,
    FOREIGN KEY (bus_id) REFERENCES bus(bus_id),
    FOREIGN KEY (driver_id) REFERENCES driver(driver_id),
    FOREIGN KEY (depot_id) REFERENCES depot(depot_id)
);

INSERT INTO bus VALUES (1, 'Model A', 'Manufacturer X'), (2, 'Model B', 'Manufacturer Y'), (3, 'Model C', 'Manufacturer Z'), (4, 'Model D', 'Manufacturer X');
INSERT INTO driver VALUES (1, 'John Doe'), (2, 'Jane Smith'), (3, 'Michael Brown'), (4, 'Laura White');
INSERT INTO depot VALUES (1, 'Depot 1', 'City A'), (2, 'Depot 2', 'City B'), (3, 'Depot 3', 'City C');

INSERT INTO trip (trip_id, segment_id, bus_id, driver_id, depot_id, trip_date, kilometers_traveled, fuel_consumption, passengers_count, trip_duration) VALUES
(1, 1, 1, 1, 1, '2023-10-01', 100, 50, 20, 180),
(2, 1, 2, 2, 2, '2023-10-02', 200, 75, 30, 240),
(3, 2, 1, 1, 1, '2023-10-03', 150, 60, 25, 200),
(4, 2, 3, 3, 2, '2023-11-01', 300, 100, 40, 360),
(5, 3, 4, 4, 3, '2023-11-02', 250, 80, 35, 320),
(6, 3, 2, 1, 1, '2023-10-01', 220, 90, 50, 300),
(7, 2, 3, 2, 2, '2023-10-02', 180, 70, 45, 270),
(8, 1, 4, 4, 3, '2023-10-03', 320, 120, 55, 400);


SELECT
    b.bus_model,
    YEAR(t.trip_date) AS trip_year,
    MONTH(t.trip_date) AS trip_month,
    DAY(t.trip_date) AS trip_day,
    SUM(t.kilometers_traveled) AS total_km,
    SUM(t.fuel_consumption) AS total_fuel_consumed,
    SUM(t.passengers_count) AS total_passengers
FROM
    trip t
JOIN bus b ON t.bus_id = b.bus_id
GROUP BY
    b.bus_model, trip_year, trip_month, trip_day;
    
    
    
    SELECT
    b.bus_model,
    YEAR(t.trip_date) AS trip_year,
    MONTH(t.trip_date) AS trip_month,
    SUM(t.kilometers_traveled) AS total_km,
    SUM(t.fuel_consumption) AS total_fuel_consumed,
    SUM(t.passengers_count) AS total_passengers
FROM
    trip t
JOIN bus b ON t.bus_id = b.bus_id
GROUP BY b.bus_model, trip_year, trip_month WITH ROLLUP;


SELECT
    b.bus_model,
    d.depot_name,
    YEAR(t.trip_date) AS trip_year,
    SUM(t.kilometers_traveled) AS total_km,
    SUM(t.fuel_consumption) AS total_fuel_consumed,
    SUM(t.passengers_count) AS total_passengers
FROM
    trip t
JOIN bus b ON t.bus_id = b.bus_id
JOIN depot d ON t.depot_id = d.depot_id
GROUP BY b.bus_model, d.depot_name, trip_year WITH CUBE;


SELECT
    b.bus_model,
    YEAR(t.trip_date) AS trip_year,
    MONTH(t.trip_date) AS trip_month,
    SUM(t.kilometers_traveled) AS total_km,
    SUM(t.fuel_consumption) AS total_fuel_consumed,
    SUM(t.passengers_count) AS total_passengers
FROM
    trip t
JOIN bus b ON t.bus_id = b.bus_id
GROUP BY b.bus_model, trip_year, trip_month WITH ROLLUP;


    
    SELECT
    b.bus_model,
    d.depot_name,
    YEAR(t.trip_date) AS trip_year,
    SUM(t.kilometers_traveled) AS total_km,
    SUM(t.fuel_consumption) AS total_fuel_consumed,
    SUM(t.passengers_count) AS total_passengers
FROM
    trip t
JOIN bus b ON t.bus_id = b.bus_id
JOIN depot d ON t.depot_id = d.depot_id
GROUP BY b.bus_model, d.depot_name, trip_year;
    