-- list of movies with both Johnny Depp and Helena Bonham Carter
SELECT title FROM movies
JOIN stars ON stars.movie_id = movies.id
JOIN people ON people.id = stars.person_id
WHERE people.name = "Johnny Depp"
AND title IN
(SELECT title FROM movies
JOIN stars ON stars.movie_id = movies.id
JOIN people on people.id = stars.person_id
WHERE people.name = "Helena Bonham Carter");
