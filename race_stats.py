#!/usr/bin/env python3  # let's just stick to python3

# TODO: remove wip notes
# TODO: are there si units in python? (eg: km to miles?)
#

def time_to_millis(strtime):
    from datetime import datetime as dt
    try:
        x = dt.strptime(strtime, "%H:%M:%S.%f")
    except ValueError as e:
        # TODO: add error message, logging?, input value checking (e.g. like j2ee bean validations)
        return 0
    return 1000 * (3600 * x.hour + 60 * x.minute + x.second) + (x.microsecond // 1000)


def calc_and_print_avg_mph(dist_miles, duration_millis):
    if (duration_millis == 0):
        return

    avg_mph = dist_miles / duration_millis * 3_600_000
    print("dist miles: ", dist_miles, "  duration_millis: ", duration_millis, "  avg mph: ", avg_mph)


def main():
    print(type(time_to_millis("0:0:0.012345")))
    print(time_to_millis("0:0:0.012345"))

    total_dist = 150.92
    laps = 4
    dist_one_lap = total_dist / laps

    last_lap_min_sec = "00:18:26.000000"
    last_lap_millis = time_to_millis(last_lap_min_sec)
    calc_and_print_avg_mph(dist_one_lap, last_lap_millis)

    total_time_hour_min_sec = "1:15:05.032"
    total_duration_millis = time_to_millis(total_time_hour_min_sec)
    calc_and_print_avg_mph(total_dist, total_duration_millis)


main()

