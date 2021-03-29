#!/usr/bin/python3

from PIL import Image

def makeCol(tup):
	return "#%02x%02x%02x" % (tup[0], tup[1], tup[2])
#XF
for i in range (1,93):

	try:
		im = Image.open("img/817%02d.gif" % i)
		pixel = im.getpixel((20,20)) 
		print ("XF%i: %s" % (i, makeCol(im.getpalette()[pixel*3 : pixel*3+3])))
	except:
		try:	
			im = Image.open("img/871%02d.jpg" % i)
			pixel = im.getpixel((150,150)) 
			print ("XF%i: %s" % (i, makeCol(pixel)))
		except Exception as e:
			pass
#AS
for i in range (1,93):

	try:
		im = Image.open("img/865%02d.gif" % i)
		pixel = im.getpixel((20,20)) 
		print ("AS%i: %s" % (i, makeCol(im.getpalette()[pixel*3 : pixel*3+3])))
	except:
		pass
