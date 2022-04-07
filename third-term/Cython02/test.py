import timeit
from fibonacciFunction import fibonacci
from fibonacciFunctionCy import fibonacci
from fibonacciFunctionCyOP import fibonacci

pyTiempo=timeit.timeit('''fb.fibonacci(1000000)''',setup='import fibonacciFunction as fb',number=400)

cyTiempo=timeit.timeit('''fbCy.fibonacci(1000000)''',setup='import fibonacciFunctionCy as fbCy',number=400)


cyOPTiempo=timeit.timeit('''fbCyOP.fibonacci(1000000)''',setup='import fibonacciFunctionCyOP as fbCyOP',number=400)


print(f"Cython es {pyTiempo/cyTiempo} más rápido\n")
print(f"CythonOP es {pyTiempo/cyOPTiempo} más rápido\n")
