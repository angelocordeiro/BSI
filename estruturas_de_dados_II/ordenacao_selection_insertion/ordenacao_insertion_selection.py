import random

def nomeAleatorio():             
  aleatorio = random.randint(0,4048)
  entrada = open('estruturas_de_dados_II/nomes_registrados_2017.csv','r', encoding = 'ISO-8859-1')
  entrada = entrada.readlines()
  linhaAleatoria = entrada[aleatorio - 1]
  return linhaAleatoria

array = []

estados = ['AC','AL','AP','AM','BA','CE','DF','ES','GO','MA','MT','MS','MG','PA',
            'PB','PR','PE','PI','RJ','RN','RS','RO','RR','SC','SP','SE','TO']

qtd = int(input("Entre com a quantidade de pessoas a ser gerado: "))


for i in range(0,qtd):
  
  pessoa = []
  nome = nomeAleatorio().replace('\n','')
  idade = random.randint(18,61)
  estado = random.choice(estados)
  pessoa.append(nome)
  pessoa.append(idade)
  pessoa.append(estado)

  array.append(pessoa)

def insercao(lista):
    for x in range(1, len(lista)):
        aux = lista[x]
        y = x-1
        while y >= 0 and aux < lista[y]:
                lista[y + 1] = lista[y]
                y -= 1
        lista[y + 1] = aux

def selecao(lista):
  for x in range(len(lista)):
      indexMin = x
      for y in range(x+1, len(lista)):
          if lista[indexMin] > lista[y]:
              indexMin = y
      lista[x], lista[indexMin] = lista[indexMin], lista[x]


opcao = int(input("Digite 1 para ordenar por insercao e 2 para ordenar por selecao: "))

if opcao == 1:
  insercao(array)
  print("Ordenado por Insercao")
elif opcao == 2:
  selecao(array)
  print("Ordenado por Selecao")
else: print("Opcao nao encontrada")

for i in range(len(array)):
      print (array[i])
