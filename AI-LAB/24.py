courses = ["AI", "ML", "DBMS", "OS", "CN", "SE"]

slots = ["Mon", "Tue", "Wed"]

neighbors = {
    "AI": ["ML", "DBMS", "SE"],
    "ML": ["AI", "OS", "CN"],
    "DBMS": ["AI", "OS"],
    "OS": ["ML", "DBMS", "CN"],
    "CN": ["ML", "OS", "SE"],
    "SE": ["AI", "CN"]
}

assignment = {}
backtracks = 0


def domain(course):

    available = []

    for slot in slots:

        if course == "DBMS" and slot == "Mon":
            continue

        safe = True

        for n in neighbors[course]:
            if n in assignment and assignment[n] == slot:
                safe = False

        if safe:
            available.append(slot)

    return available


def select_course():

    best = None
    best_domain = None

    for course in courses:

        if course not in assignment:

            d = domain(course)

            if best is None or len(d) < len(best_domain):
                best = course
                best_domain = d

    return best


def solve():

    global backtracks

    if len(assignment) == len(courses):
        return True

    course = select_course()

    for slot in domain(course):

        assignment[course] = slot

        if solve():
            return True

        del assignment[course]

    backtracks = backtracks + 1
    return False


solve()

print("Timetable:")

for course in courses:
    print(course, ":", assignment[course])

print("Backtracks:", backtracks)