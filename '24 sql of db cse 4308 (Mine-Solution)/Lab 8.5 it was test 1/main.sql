CREATE TABLE employees
(
    id int primary key,
    name varchar(255) not null,
    age int not null,
    date_of_joining date not null,
    no_of_comp_project int,
    team_name varchar(255),
    foreign key(team_name) references teams(name)
);

CREATE TABLE teams
(
    team_manager_id int primary key,
    name varchar(255) not null,
    team_manager_name varchar(255),
    project_name varchar(255) primary key,
    foreign key(team_manager_id) references employees(id),
    foreign key(project_name) references projects(name)
);

CREATE TABLE projects
(
    name varchar(255) primary key,
    budgets decimal(10,2) not null,
    deadline date not null,
    benefactor varchar(255) not null,
    scale varchar(255) not null,
    status varchar(255) not null check (status = 'complete' OR status = 'ongoing' OR status = 'on hold'),
    team_name varchar(255),
    foreign key(team_name) references teams(name)
);


-- counting quaray

select count(id) from employees where (no_of_comp_project >= 10) group by data_of_joining having (DATEDIFF('2023-10-25',data_of_joining))>=3650; -- (365 days * 10) as 10 years

-- the top three inside my dbs
select * from employees order by no_of_comp_project desc limit 3;

-- which from 25-10-2023 delayed one month
update projects
set status = 'on hold' && deadline = '25-11-2023'; -- have one month more +30 days and update status of projects as on hold

