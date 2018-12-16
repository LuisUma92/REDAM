'''_______________________________________________________    
  |                                                       |    
  |                ^                     ^                |    
  |               / \                   / \               |    
  |              / ! \     WARNING     / ! \              |    
  |             /_____\               /_____\             |    
  |                                                       |
  |_______________________________________________________|
   Analyze            
   '''
#########################
### Libraries import ####
#########################  

import random, pylab, os, math 
import numpy as np 
import matplotlib.pyplot as plt 
import datetime as dt 
import csv 

######################## 
## Outcoming function ## 
########################  

'''new_dir(output_dir = '_outcoming') create a new directory were the outcoming can be save''' 
def new_dir(name = ''):
    global output_dir     
    if name == '':         
        output_dir = 'outcoming'
    else:         
        output_dir = name     
    if not os.path.exists(output_dir):
        os.makedirs(output_dir)
      
'''We define an global string date that contains the information of the
initial time when the user runing the progrma. This information is
giveen to save each output witout delete the previous''' 
def def_now():     
    global now_date     
    now_date = dt.datetime.now().strftime("%d-%m-%Y_%H-%M-%S")  
    
'''It create an pre define document able to be appended in case  it is     
necesary to save prints output  on an  document. The appendable option     
is required to  saeve each run time''' 
def data_base(name = ''):     
    if name == '':         
        my_name = 'Base_Datos.txt'     
    else:         
        my_name = name          
    global d     
    d = open(my_name, 'a')

######################### 
## Grafication ########## 
#########################  

'''Here qe define the colors for the  grafics''' 
colors = ['r', 'b', 'g', 'orange']  

img = 0  
def histo(histo_data,name,xname,yname,title):
    def_now()
    pylab.hist(histo_data,bins=100,normed=True)
    pylab.xlabel(xname)     
    pylab.ylabel(yname)     
    pylab.title(title)     
    pylab.grid()     
    pylab.savefig('%s_%s.png' %(name,now_date))     
    plt.close('all')  
    
def this_plot(data,name,xname,yname,title):     
    x_list = [x for [x, y] in data]     
    y_list = [y for [x, y] in data]     
    plt.plot(x_list, y_list)     
    pylab.xlabel(xname)     
    pylab.ylabel(yname)     
    pylab.title(title)     
    pylab.grid()     
    pylab.savefig('Espectro_%s.png' %(name))     
    plt.close('all')  
    
######################### 
## Basic function ####### 
#########################  

def expand_BD(muestras):     
    data_base(name='Base_Datos-16-11-2017_11-47-50.txt')     
    for m in muestras:         
        for n in range(1,4):             
            fName = m+' P'+str(n)+'.TFR'             
            temp = read(fileName=fName)             
            line_end = 28 + int(temp[26][0]) 
            '''
            if m == muestras[0] and n==1:                 
                d.write('codigo pastilla ')                
                for col in range(len(temp[27])):                     
                    d.write('%s ' %(temp[27][col]))                 
                d.write('\n')             
            '''
            for line in range(28,line_end):                 
               if line == 28:                     
                   d.write('%s %i K %s ' %(m,n,temp[line][1]))                     
                   for col in range(2,len(temp[28])):                         
                       d.write('%s ' %(temp[line][col]))                 
               else:                     
                   d.write('%s %i ' %(m,n))                     
                   for col in range(len(temp[28])):                         
                       d.write('%s ' %(temp[line][col]))                
               d.write('\n')     
    d.close()   

def muestras_init():
    db = []     
    suelos = read()     
    pastos = read(fileName = 'PASTOS.csv')      
    len_pasto = len(suelos)     
    len_suelo = len(pastos)     
    print(len_pasto,len_suelo)     
    for n in range(1,len_pasto):         
        db.append(pastos[n][3])     
    for n in range(1,len_suelo):         
        db.append(suelos[n][3])      
    def_now()     
    data_base(name='codigos')     
    for m in range(len(db)):         
        d.write('%s\n'%(db[m]))     
    d.close  

def read(fileName='SUELOS.csv', delim = ',', dialec = 'unix', encod='utf-8'):     
    crimefile = open(fileName, 'r',encoding = encod)     
    reader = csv.reader(crimefile, delimiter=delim, dialect= dialec)     
    allRows = [row for row in reader]     
    crimefile.close()     
    return allRows  

######################## 
## Initation ########### 
########################  

muestras = [] 
muestra = read(fileName='codigos-06-11-2017_11-39-43.txt') 
for j in range(len(muestra)):    
   muestras.append(muestra[j][0]) 
print(muestras)  
old_db = read(fileName =  'Base_Datos-06-11-2017_20-47-26.txt', delim = ' ') 
len_old_db = len(old_db)  
pop_o = 'NONE' 
for i in range(1,len_old_db):     
    pop_n = old_db[i][0]     
    if pop_n != pop_o:         
        print(pop_n)         
        muestras.remove(pop_n)         
        pop_o = pop_n  

######################### 
## Main ################# 
#########################  
def_now() 
expand_BD(muestras) 
print(now_date) 