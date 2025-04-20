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
		