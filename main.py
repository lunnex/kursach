from _ctypes import Structure

import numpy as np
from PIL import Image
import cv2
import ctypes
import glob
import ctypes

from ctypes import *

class Matrix(Structure):
 _fields_ = [("a", c_int),
             ("array", (c_int * 100) * 100)]



m = Matrix()


hllDll = ctypes.CDLL("./x64/Debug/mpdll.dll")
# Load DLL into memory.
#hllDll.print.argtypes = [POINTER(Matrix)]
#hllDll.print.restype = None
hllDll.bar()

def open(name):
 img = Image.open(name)
 arr = np.asarray(img, dtype='uint8')
 arr.flags.writeable = True
 return arr

arr = cv2.imread("smile.png")



#cv2.imshow('KOT', img)





def vectorizing(arr):

 result = [[]]

 for i in range (0, len(arr)):
  row = []
  for j in range (0, len(arr[0])):
   if (arr[i][j][0] == [255] and arr[i][j][1] == [255] and arr[i][j][2] == [255]):
    m.array[i][j] = 1
   else:
    m.array[i][j] = 0
  result.append(row)
 return result

a = vectorizing(arr)


hllDll.Init(byref(m))


hllDll.Dilatation.restype = ctypes.POINTER(Matrix)
ret = hllDll.Dilatation(2)
print(ret.contents.array[0][0])


#for i in range (0, len(arr)):
# print ('{')
 #for j in range (0, len(arr[0])):
 # if(j > 99):
 #  print (str(result[j]) + ',')
#  else:
#   print (str(result[j]))
# print('},')
