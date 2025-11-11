use a ;

-- 1
select * from pokemon_attacks join pokemon join attacks
where pokemon_attacks.pokemon_id = pokemon.pokemon_id and pokemon_attacks.attack_id = attacks.attack_id and length(pokemon.name) > 1 and  pokemon.name = attacks.attack_name; 
-- 2
select * from owner join pokemon join trainer join attacks
where owner.trainer_id = trainer.trainer_id and pokemon.type = "Fire" and attacks.attack_power > 50; 
-- 3
select concat(pokemon.name, " --") as "name pokemon --",concat(attacks.attack_name, " --")  as "name --",attacks.attack_power as "power" from pokemon join attacks join pokemon_attacks where pokemon.pokemon_id = pokemon_attacks.pokemon_id and  attacks.attack_id = pokemon_attacks.attack_id;
-- issue of the if 4 task
-- 4
select concat(trainer.first_name," ",trainer.last_name) as "full name" from owner join pokemon join trainer join attacks
where owner.trainer_id = trainer.trainer_id and pokemon.hp + pokemon.attack + pokemon.defense + pokemon.speed ; 

-- 5
DELIMITER $$
CREATE PROCEDURE calculate_attack_avarage()

BEGIN
select pokemon.name,attacks.attack_power  from pokemon_attacks join pokemon join attacks
where pokemon_attacks.pokemon_id = pokemon.pokemon_id and pokemon_attacks.attack_id = attacks.attack_id  ; 
if 2 > count(pokemon.pokemon_id) then
	for 1..count(pokemon.pokemon_id) loop 
		if(pokemon_attacks.attack_id = attacks.attack_id)
		avarage := attack_power + avarage
    end loop
END $$
DELIMITER ;

-- 9 issue with rollup syntax
	select * from owner join trainer 
	where owner.trainer_id = trainer.trainer_id
    GROUP by CUBE(trainer.city);


-- 6 trigger 
CREATE TRIGGER updates
AFTER INSERT ON pokemon 
FOR EACH ROW
    UPDATE pokemon join pokemon_attack join attacks
    SET hp = hp * 1.2 and attack = attack * 1.2 and defense = 1.20 and speed = speed * 1.2
    WHERE pokemon.pokemon_id = pokemon_attack.pokemon_id and attack.attack_id = pokemon_attack.attack_id ;
;


-- task 8 
DECLARE pokenm_trainer CURSOR FOR 
SELECT * FROM pokemon;

BEGIN
    OPEN trainer;
    FETCH trainer INTO trainer_id;
    WHILE trainer%FOUND LOOP
        DBMS_OUTPUT.PUT_LINE(trainer_id);
        FETCH pokenm_trainer INTO trainer_id;
    END LOOP;
    CLOSE emp_cursor;
END;

-- 10
CREATE PROCEDURE delete_pokemon_with_low_stats(
    IN threshold INT
)
BEGIN
    DELETE FROM pokemon 
    WHERE pokemon.pokemon_id = attactk_pokemon.pokemon_id and attactk_pokemon.attack_id = attack.attack_id and (attack.hp+attack.speed+attack.defence+attack.attack) < threshold;
END $$
