from datetime import datetime

# LC 1507. Reformat Date
class Solution:
    def reformatDate(self, date: str) -> str:
        parts = date.split(' ')
        parts[0] = parts[0][:-2]
        date_modified = ' '.join([parts[0], parts[1], parts[2]])
        date_obj = datetime.strptime(date_modified, '%d %b %Y') # %b represents the abbreviated month name(Jan, Feb,... etc)
        return date_obj.strftime('%Y-%m-%d') # shows the format: yyyy-mm-dd, the '-' can be changed to another symbol


# LC 13. Roman to Integer
class Solution:
    def romanToInt(self, s: str) -> int:
        values = {
            "I": 1,
            "V": 5,
            "X": 10,
            "L": 50,
            "C": 100,
            "D": 500,
            "M": 1000,
                }
        num = 0
        i = 0
        while i < len(s):
            if i + 1 < len(s) and values[s[i]] < values[s[i + 1]]:
                num += values[s[i + 1]] - values[s[i]]
                i += 2
            else:
                num += values[s[i]]
                i += 1
        return num

# LC 12. Integer to Roman
class Solution:
    def intToRoman(self, num: int) -> str:
        roman_num = ""
        if num >= 1000:
            roman_num += "M" * (num // 1000)
            num = num % 1000
        if num >= 100:
            hundreds = num // 100
            if hundreds == 9:
                roman_num += "CM"
            elif hundreds == 4:
                roman_num += "CD"
            elif hundreds >= 5:
                roman_num += "D" + "C"*((num - 500) // 100)
            else: roman_num += "C"* (num // 100)
            num = num % 100
        if num >= 10:
            tens = num // 10
            if tens == 9:
                roman_num += "XC"
            elif tens == 4:
                roman_num += "XL"
            elif tens >= 5:
                roman_num += "L" + "X"*((num - 50) // 10)
            else: roman_num += "X"* (num // 10)
            num = num % 10
        if num == 9:
            return roman_num + "IX"
        if num == 4:
            return roman_num + "IV"
        if num >= 5:
            return roman_num + "V" + "I"*(num - 5)
        return roman_num + "I" * num


    # another approach
    def intToRoman2(self, num: int) -> str:
        roman_numerals = [
            (1000, "M"), (900, "CM"), (500, "D"), (400, "CD"),
            (100, "C"), (90, "XC"), (50, "L"), (40, "XL"),
            (10, "X"), (9, "IX"), (5, "V"), (4, "IV"),
            (1, "I")
        ]

        roman_num = ""
        for value, symbol in roman_numerals:
            while num >= value:
                roman_num += symbol
                num -= value
        return roman_num




