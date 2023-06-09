# inheritance
##1
Условие: Реализуйте иерархию классов для геометрических фигур: треугольник, круг, прямоугольник. Каждая фигура должна иметь методы для вычисления периметра и площади.
Формат ввода: На первой строке вводится количество фигур n (1 <= n <= 10), далее на n строках поочередно вводится тип фигуры (triangle, circle, rectangle) и параметры соответствующей фигуры (для треугольника - длины трех сторон, для круга - радиус, для прямоугольника - длины двух сторон). Все числа вводятся через пробел.
Формат вывода: Для каждой фигуры на отдельной строке выводятся ее тип, периметр и площадь. Периметр и площадь выводятся с точностью до двух знаков после запятой.
Ввод: 
3
circle 2
triangle 2 2 2
rectangle 2 3
Вывод:
circle 12.57 12.57
triangle 6.00 1.73
rectangle 10.00 6.00


##2 
Необходимо создать иерархию классов, описывающих животных. Каждое животное имеет имя и возраст, а также свои уникальные характеристики. Создайте классы для следующих животных:
•	Собака: порода и уровень дрессировки (целое число от 1 до 10).
•	Кошка: порода и цвет шерсти.
•	Жираф: длина шеи (в метрах) и цвет.
Напишите программу, которая будет считывать информацию о животных из стандартного потока ввода и выводить ее в стандартный поток вывода в следующем формате: "Имя животного, возраст лет: тип животного, порода/длина шеи/цвет шерсти, уровень дрессировки/цвет."
Формат ввода:
Первая строка содержит целое число n (1 ≤ n ≤ 100) - количество животных.
Следующие n строк содержат информацию об отдельном животном в следующем формате:
•	первое слово - тип животного (dog/cat/giraffe)
•	второе слово - имя животного (строка без пробелов)
•	третье слово - возраст животного (целое число от 1 до 100)
•	оставшиеся слова - уникальные характеристики животного в зависимости от его типа.
Формат вывода:
Для каждого животного выведите информацию в отдельной строке в формате, описанном выше.
Ввод:
3
catBoris 2 british gray
dog Rex 5 bulldog 6
giraffe Neck 10 112 yellow
Вывод:
Boris, 2 years old: cat, british, gray.
Rex, 5 years old: dog, bulldog, level of training 6.
Neck, 10 years old: giraffe, neck length 112.000000 m, yellow.


##3
Напишите программу, которая моделирует систему оплаты. Есть два типа клиентов: обычные и VIP. Каждый клиент имеет уникальный номер и баланс на счету. Обычные клиенты могут пополнять свой баланс, снимать деньги и проверять свой баланс. VIP-клиенты имеют дополнительные привилегии: они могут получать бонусы за каждое пополнение счета и имеют скидку на снятие денег.
Программа должна иметь следующие возможности:
•	Создание клиента: обычный или VIP.
•	Пополнение счета клиента.
•	Снятие денег со счета клиента.
•	Проверка баланса клиента.
•	Печать информации о клиенте (номер, тип, баланс).
Формат ввода:
Каждая строка входных данных содержит запрос в одном из форматов:
•	"create client" с информацией о клиенте: уникальный номер (строка без пробелов), тип клиента ("ordinary" или "vip"), баланс (целое число);
•	"add money" с информацией о клиенте: уникальный номер (строка без пробелов), сумма пополнения (целое число);
•	"withdraw money" с информацией о клиенте: уникальный номер (строка без пробелов), сумма снятия (целое число);
•	"check balance" с информацией о клиенте: уникальный номер (строка без пробелов);
•	"print info" с информацией о клиенте: уникальный номер (строка без пробелов).
Формат вывода:
Для каждого запроса выводить результат в соответствии с запросом в следующем формате:
•	"create client" - ничего не выводить;
•	"add money" - ничего не выводить;
•	"withdraw money" - если денег достаточно для снятия, то вывести сообщение "Withdrawal successful", иначе - "Insufficient funds";
•	"check balance" - вывести текущий баланс;
•	"print info" - вывести информацию о клиенте в следующем формате: "Client <номер>: <тип>, баланс <баланс>".
Ввод:
create
1 vip 1000
info
1
add
1 100
withdraw
1 200
info
1
create
2 ordinary 1000
add
2 100
withdraw
2 200
info
2
Вывод:
Client 1: VIP, balance 1000, 0 bonuses
Withdrawal successful
Client 1: VIP, balance 920, -16 bonuses
Withdrawal successful
Client 2: ordinary, balance 900


##4
Условие задания:
Разработайте игру-стратегию, в которой есть несколько типов юнитов. Каждый юнит имеет определенные характеристики, такие как уровень здоровья, скорость передвижения, урон и т.д. Также, юниты могут быть оборудованы различными предметами, которые улучшают их характеристики. Разработайте программу, которая позволит создавать юнитов и добавлять к ним различные предметы.
Формат ввода:
Первая строка содержит число n - количество юнитов. Далее следуют n строк, каждая из которых описывает юнита. В первой строке указывается тип юнита (warrior, mage или knight). Далее следуют значения характеристик: уровень здоровья, скорость передвижения, урон и т.д. Если у юнита есть предметы, то далее следует число m - количество предметов, и m строк, каждая из которых описывает предмет. В первой строке указывается тип предмета (armor, weapon или boots). Далее следуют значения характеристик предмета, такие как бонус к здоровью, скорости или урону.
Формат вывода:
Для каждого юнита необходимо вывести информацию об его характеристиках, а также список примененных предметов с указанием их характеристик.
Ввод:
Enter the number of units: 3
Enter unit type, health, speed and damage: mage 75 20 30
Enter the number of items for this unit: 1
Enter item type, health bonus, speed bonus and damage bonus: weapon 10
Enter unit type, health, speed and damage: knight 150 10 10
Enter the number of items for this unit: 1
Enter item type, health bonus, speed bonus and damage bonus: armor 25
Enter unit type, health, speed and damage: warrior 100 10 15
Enter the number of items for this unit: 3
Enter item type, health bonus, speed bonus and damage bonus: armor 10
Enter item type, health bonus, speed bonus and damage bonus: boots 15
Enter item type, health bonus, speed bonus and damage bonus: weapon 5
Вывод:
mage
health: 75
speed: 20
damage: 30

Weapon:
health: 0
speed: 0
damage: 10


knight
health: 150
speed: 10
damage: 10

Armor:
health: 25
speed: 0
damage: 0


warrior
health: 100
speed: 10
damage: 15

Armor:
health: 10
speed: 0
damage: 0

Boots:
health: 0
speed: 15
damage: 0

Weapon:
health: 0
speed: 0
damage: 5


##5
Разработайте программу на C++, которая представляет иерархию классов "Животное" -> "Млекопитающее" -> "Человек". Каждый класс должен иметь свои уникальные свойства и методы, а также методы, унаследованные от предыдущего класса. Класс "Животное" должен иметь свойства "возраст", "вес" и "пол", класс "Млекопитающее" должен иметь свойства "время беременности" и методы "передвижение" и "питание", а класс "Человек" должен иметь свойства "имя", "фамилия", "дата рождения" и методы "говорить", "работать" и "учиться".
Формат ввода:
Программа должна считывать данные о каждом объекте класса из файла. Данные о каждом объекте должны быть записаны на новой строке в следующем порядке: тип объекта (животное, млекопитающее, человек), свойства объекта через пробел.
Формат вывода:
Программа должна выводить информацию о каждом объекте класса в следующем формате: тип объекта, свойства объекта через пробел.
Ввод:
Введите возраст: 20
введите вес: 47
Введите пол: female
Срок беременности: 9
Имя: liza
Фамилия: gusko
Дата рождения (dd/mm/yyyy): 24/07/2002
Вывод:
Млекопитающие передвигается
Млекопитающее кормит молоком свое потомство
Беременность матери длилась 9 месяцев
liza gusko, родилась 24/07/2002, female ,весит 47 кг, 20 лет


