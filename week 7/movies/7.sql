-- all movies released in 2010 + their ratings in descending order by rating. Movies with same rating order alphabetically by title
SELECT title, rating FROM movies
JOIN ratings ON movies.id = ratings.movie_id
WHERE year = 2010
ORDER BY rating DESC, title ASC;
