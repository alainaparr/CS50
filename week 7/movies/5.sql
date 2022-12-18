-- titles and release years of all harry potter movies; chronological
SELECT year, title FROM movies
WHERE title LIKE 'Harry Potter%'
ORDER BY year ASC;
