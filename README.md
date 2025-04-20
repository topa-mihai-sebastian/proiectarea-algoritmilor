# Tema Proiectarea Algoritmilor

## Feribot

- **Implementare**

- Am implementat funcția **`isPossible(maxCost)`** care verifică dacă se poate traversa râul cu un cost maxim `maxCost` fără a depăși `K`.

- **Inițializare:**
  - `farriesUsed = 1`, deoarece se folosește întotdeauna cel puțin un feribot.
  - `currentSum = 0`, suma greutăților încărcate pe feribotul curent.

- **Pentru fiecare mașină:**
  - Dacă ea singură depășește capacitatea `maxCost` => returnează `false`.
  - Dacă `greutatea` mașinii curente + `currentSum` > `maxCost`:
    - Incrementăm `farriesUsed++`
    - Setăm `currentSum = weight[i]`
    - Dacă `farriesUsed > K` => returnează `false`.
  - Altfel:
    - `currentSum += weight[i]`

- **Funcția `findMinCost()`:**

  - **Inițializări:**
    - `left = 0`
    - `right = sum(weights)` (greutatea maximă totală)
  
  - **Cât timp `left <= right`:**
    - `mid = left + (right - left) / 2`
    - Dacă `isPossible(mid)`:
      - Putem încerca o valoare mai mică:
        - `right = mid - 1`
        - `result = mid` (salvez soluția pe care o voi returna la final)
    - Else:
      - Încercăm o valoare mai mare (înseamnă că `mid` e prea mic):
        - `left = mid + 1`
		
## Stocks

- **La început se citesc valorile în 3 vectori separați:**
  - `buy_price`
  - `min_sell_price`
  - `max_sell_price`

- **Matricea de programare dinamică:**  
  `dp[used][loss]` conține câștigul maxim obținut pentru un buget consumat de `used` și o pierdere acumulată de `loss`.

- **Pentru fiecare acțiune:**
  - Pornim cu `used = B`. Practic, presupunem că la început, pentru fiecare acțiune, avem întregul buget disponibil.
  - Pornim cu `loss = 0`. La început, preferăm ca pierderea să fie 0.
  - Dacă suma dintre pierderea curentă (`loss`) și prețul de cumpărare al acțiunii curente (`buy_price[i]`) este mai mică sau egală cu bugetul, atunci se poate cumpăra această acțiune:
    - Se creează variabila `new_used`, în care se adaugă prețul acțiunii curente:  
      `new_used = used + buy_price[i]`
    - Se creează variabila `new_loss`, în care se adună pierderea curentă cu diferența dintre prețul acțiunii și prețul minim de vânzare:  
      `new_loss = loss + (buy_price[i] - min_sell_price[i])`
    - Dacă `new_loss` nu depășește limita `L`:
      - Se calculează `aux`, care reprezintă profitul maxim acumulat până acum plus prețul maxim de vânzare al acțiunii curente:  
        `aux = dp[used][loss] + max_sell_price[i]`
      - Se actualizează starea în matrice:  
        `dp[new_used][new_loss] = max(dp[new_used][new_loss], aux)`

- **Iterarea finală prin matrice:**
  - Se parcurge întreaga matrice `dp` pentru a calcula, pentru fiecare combinație de `used` și `loss`, profitul final obținut, scăzând `used` (cheltuielile de pana acum) din profitul acumulat.
  - Rezultatul final (profitul maxim) este maximul dintre toate aceste valori auxiliare.


## Badgpt

- De aici am luat formula: [Fast Fibonacci Algorithms](https://www.nayuki.io/page/fast-fibonacci-algorithms)

- Prin încercări repetate pe hârtie mi-am dat seama că este vorba de șirul lui Fibonacci.

- Prima dată am implementat Fibonacci clasic (prin programare dinamică) și am observat că era mult prea lent pentru majoritatea testelor. Apoi am căutat un algoritm de fast-fibo.

- Am împărțit problema într-o problemă mai mică:
  - Funcția returnează o pereche `(a, b)`.
  - Dacă `n` este impar, se returnează `(b, a+b)`.
  - Altfel, se returnează `(a, b)`.

## Procesarea numerelor din șirul de caractere

- **Scopul**:  
  Ne interesează doar numerele care apar imediat după anumite litere problematice (de exemplu, 'm', 'n', 'w', 'u'). Restul numerelor din șir sunt ignorate.

- **Calculul valorii finale**:  
  Pentru fiecare număr extras după o literă problematică:
  - Se aplică funcția `fibo(n)`, care calculează Fibonacci(n) folosind algoritmul fast doubling.
  - Din rezultatul obținut prin `fast_fibo(n)`, ne interesează **al doilea termen** (deoarece aceasta corespunde lui Fibonacci(n)).
  - Rezultatul final pentru problema "Badgpt" este produsul tuturor acestor valori de Fibonacci, adică produsul tuturor `fibo(n)` pentru fiecare număr `n` extras.

- **Explicație suplimentară**:
  - Funcția `fast_fibo(n)` returnează o pereche `(a, b)`, unde `b` este Fibonacci(n) conform algoritmului fast doubling.
  - Pentru fiecare literă problematică, se extrage numărul imediat următor, se calculează `fibo(n) = fast_fibo(n).second` și se înmulțește cu valoarile calculate anterior.