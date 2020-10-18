#1-4
# a = int(input())
# b = int(input())
# a1 = bin(a)#bin(a)将a转化为对应的二进制
# b1 = bin(b)
# c = a & b
# print(a1, b1, c)

#1-5
# a = int(input())
# b = input()
# print(chr(a), ord(b))#python内置函数：chr(a)将数字a转化为对应的ASCII码字符，ord('b')将字符b转化为对应的ASCII码值

#1-6
# a = int(input())
# x = oct(a)# 转8进制#
# y = hex(a)# 转16进制
# z = bin(a)# 转10进制
# list = [x,y,z]
# print(",".join(str(i)for i in list))

"""多行注释
1-7
a = int(input())
b = str(abs(a))
str1 = "+"
print(a)
print('%10s' % a)#右对齐10位
print(str1+b)
print('%10s' % (str1+b))
"""
#a = b"djewoif"
#print(a)
#print(type(a))

#1-8
"""
num = float(input())
#12345567.891234567
a = round(num, 6)#保留6位小数
b = format(num, "0.2f")#保留2位小数
c = round(num, 8)
d = format(num, "e")#使用e的科学计数法  1.234557e+07
d1 = format(num, "E")#使用E的科学计数法 1.234557E+07
d2 = format(num, "0.2E")#使用保留2位小数E的科学计数法 1.23E+07
e = format(num, ",")#用','作为千分位 12,345,567.891234567
list = [a, b, c, d, d1, d2, e]
print("/".join(str(i) for i in list))
"""
#num = float(input())
#print(round(num, 6), format(num, "0.2f"), round(num, 8), format(num, "e"), format(num, ","), sep = "/")
#1-9

# num = int(input())
# a = bin(num).replace('0b', '', 1)#str.replace(old, new, max)将old字符串替换成new字符串，替换次数不超过max次
# b = oct(num).replace('0o', '', 1)
# b1 = oct(num)
# c = hex(num).replace('0x', '', 1)
# c1 = hex(num)
# c3 = c1.replace('x', 'X', 1).replace('b', 'B', 1)
# list = [a, b, b1, c, c1, c3]
# print(",".join(str(i) for i in list))

# a = int(input())
# print('{:b}'.format(a), '{:o}'.format(a), oct(a), '{:x}'.format(a), hex(a), '{:#X}'.format(a), sep = ",")

#1-10
# m = int(input())
# n = int(input())
# str = bin(m).replace("0b", '')
# a = str.rjust(n, '0')#字符串左对齐n位不够补0
# print(a)

#2-1
# from fractions import Fraction
# a = float(input())
# print(Fraction(a).limit_denominator())#将浮点数转化为分数形式输出

#2-2
# from fractions import Fraction
# a = int(input())
# b = int(input())
# c = int(input())
# d = int(input())
# f1 = Fraction(a,b)
# f2 = Fraction(c,d)
# print('(',f1,')','+(',f2,')=',f1+f2,sep='')
# print('(',f1,')','-(',f2,')=',f1-f2,sep='')
# print('(',f1,')','*(',f2,')=',f1*f2,sep='')
# print('(',f1,')','/(',f2,')=',f1/f2,sep='')

#2-3
# person_age = float(input())
# if person_age <= 2 :
#     dog_age = 10.5 * person_age
# else:
#     dog_age = (person_age - 2) * 4 + 10.5 * 2
# print(int(dog_age))

#2-4
# v = int(input())
# t = int(input())
# print(round((13.12+0.6215*t-11.37*v**0.16+0.3965*t*v**0.16)))

#2-5
# h = float(input())
# r = float(input())
# PI = 3.14159265
# print('%.4f' % (PI*r*r*h))
# print('%.4f' % (2*PI*r*r+2*PI*r*h))

#2-6????????????????????????????????????????????????????????????????????????????????????????????????????????
# a = int(input())
# b = int(input())
# c = (a*a + b*b)**0.5
# if a*a +b*b == c*c or a*a + c*c == b*b or b*b + c*c == a*a :

# if type(c) == "<class 'float'>":
#     print("non")
# elif type(c)=="<class 'int'>":
#     print("c")

#2-7
# f = float(input())
# n = int(input())
# print(round(f,n))

#2-8
# R = int(input())
# G = int(input())
# B = int(input())
# R, G, B = R / 255.0, G / 255.0, B / 255.0
# Max = max(R, G, B)
# Min = min(R, G, B)
# V = Max
# if V == 0:
#     S = 0;
# else:
#     S = (Max - Min) / Max
# if Max == R:
#     H = 60 * (0 + (G - B) / (Max - Min))
# elif Max == G:
#     H = 60 * (2 + (B - R) / (Max - Min))
# elif Max == B:
#     H = 60 * (4 + (R - G) / (Max - Min))
# if H < 0:
#     H = H + 360
# print('%.4f' % H, ('%.4f' % (S*100))+'%', ('%.4f' % (V*100))+'%', sep=',')

#2-9
# from math import radians, cos, sin, asin
# r = 6371
# lat1 = float(input())
# lon1 = float(input())
# lat2 = float(input())
# lon2 = float(input())
# lon1, lat1, lon2, lat2 = map(radians, [lon1, lat1, lon2, lat2])
# a = sin((lat2-lat1)/2) * sin((lat2-lat1)/2)
# b = sin((lon2-lon1)/2) * sin((lon2-lon1)/2)
# d = 2*r*(asin((a+cos(lat1)*cos(lat2)*b)**0.5))
# print(('%.4f' % d)+'km')

#2-10
# import math
# x = float(input())
# y = float(input())
# x1 = (x**2 + y**2)**0.5
# y1 = math.atan(y/x)
# print('%.4f' % x1, '%.4f' % y1, sep=',')