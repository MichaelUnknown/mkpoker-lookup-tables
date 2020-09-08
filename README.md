# mkpoker lookup tables
Script to generate lookup tables for straights and 3 or 5 kickers (to be used with one pair / no pair).

Straight table:  
We use the simple approach of counting consecutive ranks (i.e., consecutive bits of the input) until we find 5 set bits in a row. The ace is represented as the highest bit, so a check is provided if there is a straight with a low ace.

Top 3 / Top 5 tables:  
Starting with the highest bit, we count until we find 3 (5) set bits or the lowest bit is reached. If the threshold is met, we clear the remaining bits.
