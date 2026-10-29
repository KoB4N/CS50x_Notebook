-- The names of songs that feature other artists.
-- "feat."
SELECT name 
FROM songs
WHERE name LIKE "%feat.%"