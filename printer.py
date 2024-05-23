import pyautogui as pg
import pyscreeze
import win32gui
import win32api
import win32con
import os
import time
import math as m
import keyboard
from PIL import Image

def circ(r, deg):
    return m.sin(deg*m.pi/180)*r, m.cos(deg*m.pi/180)*r
def click(x,y):
    win32api.SetCursorPos((x,y))
    win32api.mouse_event(win32con.MOUSEEVENTF_LEFTDOWN, 0, 0)
    
    win32api.mouse_event(win32con .MOUSEEVENTF_LEFTUP, 0, 0)

time.sleep(3)
r = 15
a = [[1,1,1],[0,1,0],[0,1,1]]
filename = r"path"
with Image.open(filename) as img:
    img.load()

img = img.resize((img.width//3, img.height//3))
img = img.convert('1')


for i in range(img.height):
    for j in range(img.width):
        if img.getpixel((j,i)) ==0:
            pg.click()
        pg.moveRel(r,0)
    pg.moveRel(-r*img.width,r)






