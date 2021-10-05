import random

def nomeAleatorio():             
  aleatorio = random.randint(0,4048)
  entrada = open('Estruturas de dados II/nomes-registrados-2017.csv','r', encoding = 'ISO-8859-1')
  entrada = entrada.readlines()
  linhaAleatoria = entrada[aleatorio - 1]
  return linhaAleatoria

array = []

estados = ['AC','AL','AP','AM','BA','CE','DF','ES','GO','MA','MT','MS','MG','PA',
            'PB','PR','PE','PI','RJ','RN','RS','RO','RR','SC','SP','SE','TO']

for i in range(0,10):
  
  pessoa = []
  nome = nomeAleatorio().replace('\n','')
  idade = random.randint(18,61)
  estado = random.choice(estados)
  pessoa.append(nome)
  pessoa.append(idade)
  pessoa.append(estado)

  array.append(pessoa)

for i in array:
  print(i)