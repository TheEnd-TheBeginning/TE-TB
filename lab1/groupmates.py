#coding:utf-8
groupmates = [
    {
        "name": u"Лиза",
        "grop": "1851",
        "age":22,
        "marks":[4,5,4,5,5]
    },
    {
        "name": u"Мария",
        "grop": "1851",
        "age":20,
        "marks":[4,5,4,5,5]
    },
    {
        "name": u"Алексей",
        "grop": "1851",
        "age":25,
        "marks":[4,5,4,5,5]
    },
    {
        "name": u"Максим",
        "grop": "1851",
        "age":23,
        "marks":[4,5,4,5,5]
    },
    {
        "name": u"Володя",
        "grop": "1851",
        "age":35,
        "marks":[4,5,4,5,5]
    }
]
def print_students(students):
    print u"Имя студента".ljust(15), \
          u"Группа".ljust(8), \
          u"Возраст".ljust(8), \
          u"Оценки".ljust(20)
    for student in students:
        print \
            student["name"].ljust(15), \
            student["group"].ljust(8), \
            str(student["age"]).ljust(8), \
            str(student["marks"].ljust(20)
    print("\n")
    
print_students(groupmates)
