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
SELECT DISTINCT city FROM station WHERE LOWER(SUBSTR(city,1,1)) NOT IN ('a','e','i','o','u') AND LOWER(SUBSTR(city, LENGTH(city),1)) NOT IN ('a','e','i','o','u');

SELECT city, LENGTH(city) FROM station ORDER BY LENGTH(city) ASC, city LIMIT 1; 
SELECT city, LENGTH(city) FROM station ORDER BY LENGTH(city) DESC, city LIMIT 1; 


* Not using my time efficiently. Need to plan office & home hours properly. 
```
---
#### Day-2
```
* HACKERRANK :: sql
SELECT ROUND(SUM(lat_n), 2), ROUND(SUM(long_w), 2) FROM station;
SELECT ROUND(SUM(lat_n), 4) FROM station where lat_n > 38.7880 AND lat_n < 137.2345;
SELECT ROUND(MAX(lat_n), 4) FROM station WHERE lat_n < 137.2345;
SELECT ROUND(long_w, 4) FROM station WHERE lat_n < 137.2345 ORDER BY lat_n DESC LIMIT 1;
SELECT ROUND(MIN(lat_n), 4) FROM station WHERE lat_n > 38.7780;
SELECT ROUND(long_w, 4) FROM station WHERE lat_n > 38.7780 ORDER BY lat_n ASC LIMIT 1;
SELECT ROUND(ABS(MIN(lat_n) - MAX(lat_n)) + ABS(MIN(long_w) - MAX(long_w)), 4) FROM station;
SELECT ROUND(SQRT(POW(MIN(lat_n) - MAX(lat_n), 2) + POW(MIN(long_w) - MAX(long_w), 2)), 4) FROM station;

SET @rowIndex := -1;
SELECT ROUND(AVG(a.lat_n), 4) FROM (
SELECT @rowIndex := @rowIndex+1 AS rowIndex, b.lat_n FROM STATION AS b ORDER BY b.lat_n
) AS a WHERE a.rowIndex IN (FLOOR(@rowIndex / 2), CEIL(@rowIndex / 2));

	
SELECT 
	IF(a+b>c AND a+c>b AND b+c>a, 
		IF(a=b AND b=c, 'Equilateral', 
		IF(a=b OR b=c OR a=c, 'Isosceles', 'Scalene')), 'Not A Triangle') 
	FROM triangles;
	
SELECT COUNT(population) FROM city WHERE population > 100000;
SELECT SUM(population) FROM city WHERE district = 'California';
SELECT AVG(population) FROM city WHERE district = 'California';
SELECT SUM(population) FROM city WHERE countrycode = 'JPN';
SELECT MAX(population) - MIN(population) FROM city;
---
* Not using my time efficiently. Need to plan office & home hours properly. 
---
```
---