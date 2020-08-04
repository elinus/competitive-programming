# 100 Days of code

---
#### Day-0
```
- Motivation: develop problem-solving skills. 
- First, try to solve the problems from interview_bit, 
  Once it is complete, move to leetcode-pro, hackerrank, gfg etc. 
- Solve 3-5 problems daily and upload it to Github and update this read-me.
- In case of failed to upload, do not reset the count.
- Do not try to re-invent the wheel.
- Spend 15-20-25 mins on the problem. Check solutions do not get stuck.
- Learn c++ in deep
```
---
#### Day-1
```
* HACKERRANK :: sql
SELECT * FROM city WHERE countrycode = 'USA' AND population > 100000;
SELECT name FROM city WHERE countrycode = 'USA' AND population > 120000;
SELECT * FROM city;
SELECT * FROM city WHERE id = 1661;
SELECT * FROM city WHERE countrycode = 'JPN';
SELECT name FROM city WHERE countrycode = 'JPN';
SELECT city, state FROM station;
SELECT city FROM station WHERE MOD(id,2) = 0 GROUP BY city;
SELECT COUNT(city) - COUNT(DISTINCT city) FROM station;
SELECT name FROM employee ORDER BY name;
SELECT name FROM employee WHERE salary > 2000 AND months < 10 ORDER BY employee_id;
SELECT DISTINCT city FROM station WHERE city REGEXP '^[aeiou]';
SELECT DISTINCT city FROM station WHERE city REGEXP '[aeiou]$';
SELECT DISTINCT city FROM station WHERE city NOT REGEXP '^[aeiou]';
SELECT DISTINCT city FROM station WHERE city NOT REGEXP '[aeiou]$';
SELECT DISTINCT city FROM station WHERE city RLIKE '^[aeiouAEIOU].*[aeiouAEIOU]$';
SELECT DISTINCT city FROM station WHERE city NOT RLIKE '^[aeiouAEIOU].*[aeiouAEIOU]$';
SELECT DISTINCT city FROM station WHERE city NOT RLIKE '^[AEIOUaeiou].*$';
SELECT name FROM students WHERE marks > 75 ORDER BY SUBSTRING(name, -3, 3), id;
SELECT DISTINCT city FROM station WHERE LOWER(SUBSTR(city,1,1)) NOT IN ('a','e','i','o','u') AND 		LOWER(SUBSTR(city, LENGTH(city),1)) NOT IN ('a','e','i','o','u');

SELECT city, LENGTH(city) FROM station ORDER BY LENGTH(city) ASC, city LIMIT 1; 
SELECT city, LENGTH(city) FROM station ORDER BY LENGTH(city) DESC, city LIMIT 1; 


* Not using my time efficiently. Need to plan office & home hours properly. 
```