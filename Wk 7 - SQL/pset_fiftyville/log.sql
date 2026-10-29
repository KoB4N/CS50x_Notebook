-- Keep a log of any SQL queries you execute as you solve the mystery.
-- Who the thief is,
-- What city the thief escaped to, and
-- Who the thief’s accomplice is who helped them escape

-- crime_scene_reports
-- +-----------------------------------------------------------------------+
-- |                              description                              |
-- +-----------------------------------------------------------------------+
-- |Theft of the CS50 duck took place at 10:15am at the Humphrey Street    |
-- |bakery. Interviews were conducted today with three witnesses who were  |
-- |present at the time – each of their interview transcripts mentions the |
-- |bakery.                                                                |
-- +-----------------------------------------------------------------------+ 
SELECT description 
FROM crime_scene_reports
WHERE year = 2025 AND month = 7 AND day = 28 AND street = "Humphrey Street" AND description LIKE "%Theft%";

-- interviews
-- +-------+---------------------------------------------------------------+
-- | name  |                          transcript                           |
-- +-------+---------------------------------------------------------------+
-- |Ruth   |Sometime within ten minutes of the theft, I saw the thief get  |
-- |       |into a car in the bakery parking lot and drive away. If you    |
-- |       |have security footage from the bakery parking lot, you might   |
-- |       |want to look for cars that left the parking lot in that time   |
-- |       |frame.                                                         |
-- +-------+---------------------------------------------------------------+
-- |Eugene |I don't know the thief's name, but it was someone I recognized.|
-- |       |Earlier this morning, before I arrived at Emma's bakery, I was |
-- |       |walking by the ATM on Leggett Street and saw the thief there   |
-- |       |withdrawing some money.                                        |
-- +-------+---------------------------------------------------------------+
-- |Raymond|As the thief was leaving the bakery, they called someone who   |
-- |       |talked to them for less than a minute. In the call, I heard the|
-- |       |thief say that they were planning to take the earliest flight  |
-- |       |out of Fiftyville tomorrow. The thief then asked the person on |
-- |       |the other end of the phone to purchase the flight ...          |
-- +-------+---------------------------------------------------------------+
SELECT name, transcript
FROM interviews
WHERE year = 2025 AND month = 7 AND day = 28 AND transcript LIKE "%bakery%";

-- bakery_security_logs
-- +---------------+------+--------+----------+
-- | license_plate | hour | minute | activity |
-- +---------------+------+--------+----------+
-- | 5P2BI95       |   10 |     16 | exit     |
-- | 94KL13X       |   10 |     18 | exit     |
-- | 6P58WS2       |   10 |     18 | exit     |
-- | 4328GD8       |   10 |     19 | exit     |
-- | G412CB7       |   10 |     20 | exit     |
-- | L93JTIZ       |   10 |     21 | exit     |
-- | 322W7JE       |   10 |     23 | exit     |
-- | 0NTHK55       |   10 |     23 | exit     |
-- +---------------+------+--------+----------+
SELECT license_plate, hour, minute, activity
FROM bakery_security_logs
WHERE year = 2025 AND month = 7 AND day = 28 AND hour = 10 AND minute <= 25 AND activity = "exit"; 

-- atm_transactions
-- +----------------+------------------+--------+
-- | account_number | transaction_type | amount |
-- +----------------+------------------+--------+
-- |       28500762 | withdraw         |     48 |
-- |       28296815 | withdraw         |     20 |
-- |       76054385 | withdraw         |     60 |
-- |       49610011 | withdraw         |     50 |
-- |       16153065 | withdraw         |     80 |
-- |       25506511 | withdraw         |     20 |
-- |       81061156 | withdraw         |     30 |
-- |       26013199 | withdraw         |     35 |
-- +----------------+------------------+--------+
SELECT account_number, transaction_type, amount
FROM atm_transactions
WHERE year = 2025 AND month = 7 AND day = 28 AND atm_location = "Leggett Street" AND transaction_type = "withdraw"; 

-- bank_accounts
-- +-----------+
-- | person_id |
-- +-----------+
-- |    686048 |
-- |    514354 |
-- |    458378 |
-- |    395717 |
-- |    396669 |
-- |    467400 |
-- |    449774 |
-- |    438727 |
-- +-----------+
SELECT person_id
FROM bank_accounts
WHERE account_number IN
(
    SELECT account_number
    FROM atm_transactions
    WHERE year = 2025 AND month = 7 AND day = 28 AND atm_location = "Leggett Street" AND transaction_type = "withdraw" 
);

-- phone_calls
-- +----------------+----------------+----------+
-- |     caller     |    receiver    | duration |
-- +----------------+----------------+----------+
-- | (130) 555-0289 | (996) 555-8899 |       51 |
-- | (499) 555-9472 | (892) 555-8872 |       36 |
-- | (367) 555-5533 | (375) 555-8161 |       45 |
-- | (499) 555-9472 | (717) 555-1342 |       50 |
-- | (286) 555-6063 | (676) 555-6554 |       43 |
-- | (770) 555-1861 | (725) 555-3243 |       49 |
-- | (031) 555-6622 | (910) 555-3251 |       38 |
-- | (826) 555-1652 | (066) 555-9701 |       55 |
-- | (338) 555-6650 | (704) 555-2131 |       54 |
-- +----------------+----------------+----------+
SELECT caller, receiver, duration
FROM phone_calls
WHERE year = 2025 AND month = 7 AND day = 28 AND duration < 60;

-- +----+----------------------+------+--------+
-- | id | destination_airpo... | hour | minute |
-- +----+----------------------+------+--------+
-- | 18 |                    6 |   16 |      0 |
-- | 23 |                   11 |   12 |     15 |
-- | 36 |                    4 |    8 |     20 |
-- | 43 |                    1 |    9 |     30 |
-- | 53 |                    9 |   15 |     20 |
-- +----+----------------------+------+--------+
SELECT id, destination_airport_id, hour, minute 
FROM flights
WHERE year = 2025 AND month = 7 AND day = 29 AND origin_airport_id IN
(
    -- airports
    -- +----+
    -- | id |
    -- +----+
    -- |  8 |
    -- +----+
    SELECT id 
    FROM airports
    WHERE city = "Fiftyville"
);

-- passengers
-- +-----------------+
-- | passport_number |
-- +-----------------+
-- |      7214083635 |
-- |      1695452385 |
-- |      5773159633 |
-- |      1540955065 |
-- |      8294398571 |
-- |      1988161715 |
-- |      9878712108 |
-- |      8496433585 |
-- +-----------------+
SELECT passport_number
FROM passengers
JOIN flights ON passengers.flight_id = flights.id
WHERE flights.id IN 
(
    SELECT id
    FROM flights
    WHERE id = 36 AND year = 2025 AND month = 7 AND day = 29 AND hour = 8 AND minute = 20 AND origin_airport_id IN
    (
        SELECT id 
        FROM airports
        WHERE city = "Fiftyville"
    )
);

-- people 
-- Thief Identity:
-- +-------+
-- | name  |
-- +-------+
-- | Bruce |
-- +-------+
SELECT name
FROM people
WHERE phone_number IN
(
    SELECT caller
    FROM phone_calls
    WHERE year = 2025 AND month = 7 AND day = 28 AND duration < 60
)
AND id IN
(
    SELECT person_id
    FROM bank_accounts
    WHERE account_number IN
    (
        SELECT account_number
        FROM atm_transactions
        WHERE year = 2025 AND month = 7 AND day = 28 AND atm_location = "Leggett Street" AND transaction_type = "withdraw" 
    )
)
AND license_plate IN
(
    SELECT license_plate
    FROM bakery_security_logs
    WHERE year = 2025 AND month = 7 AND day = 28 AND hour = 10 AND minute <= 25 AND activity = "exit"
)
AND passport_number IN
(
    SELECT passport_number
    FROM passengers
    JOIN flights ON passengers.flight_id = flights.id
    WHERE flights.id IN 
    (
        SELECT id
        FROM flights
        WHERE id = 36 AND year = 2025 AND month = 7 AND day = 29 AND hour = 8 AND minute = 20 AND origin_airport_id IN
        (
            SELECT id 
            FROM airports
            WHERE city = "Fiftyville"
        )
    )
);

-- airports
-- City Thief Escape:
-- +---------------+
-- |     city      |
-- +---------------+
-- | New York City |
-- +---------------+
SELECT city
FROM airports
JOIN flights ON airports.id = flights.destination_airport_id
WHERE flights.id = 36;

-- people
-- Thief Accomplice:
-- +-------+
-- | name  |
-- +-------+
-- | Robin |
-- +-------+
SELECT name 
FROM people 
WHERE phone_number IN
(
    SELECT receiver
    FROM phone_calls
    WHERE year = 2025 AND month = 7 AND day = 28 AND duration < 60 AND caller IN 
    (
        SELECT phone_number
        FROM people
        WHERE name = "Bruce"
    )
);