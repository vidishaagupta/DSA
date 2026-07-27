-- Employee Bonus
select e.name,b.bonus
from Employee e
LEFT JOIN bonus b
on e.empId=b.empId 
WHERE b.bonus<1000 or
b.bonus is null 

--Find Customer Referee
select name from Customer
where referee_id != 2 OR referee_id is NULL;

--Not Boring movies
select * from Cinema where 
id%2=1 AND 
description!= "boring" 
order by rating DESC;

--Combine Two Tables
select p.firstName,p.lastName,a.city, a.state 
from Person p
LEFT JOIN Address a 
on p.personId= a.personId    

