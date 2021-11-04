# Task #6: Programación concurrente  
**course:** Programación Orientada a Objetos II  
**unit:** 5  
**cmake project:** poo2_unit5_concurrencia_poo_v2021_2
## Instructions

## Question #1 - Suma concurrente (5 points)

Implementar una función **`sumar`** que utilizando concurrencia realice la suma de todo los valores numericos de un
contenedor secuencial. Generalizar el programa para que acepte cualquier tipo de contenedor secuencial.
```cpp
template <typename T, template <typename...> class Container>
T sumar(Container<T>& cnt);
```
**Casos de uso**
```cpp
    size_t n = 0;
    cin >> n;
    vector<long long> v1(n);
    for (auto &item: v1)
        cin >> item;
    auto total = sumar(v1);
    cout << total << endl;
```

## Question #2 - Incremento Concurrente (5 points)

Implementar una función **`increase_values`** que utilizando concurrencia realice incremente todos los valores de un vector en
un valor dado. Generalizar el programa para que acepte cualquier tipo de contenedor secuencial.
```cpp
template<typename T, template<typename ...> class Container>
void increase_values(Container<T>& cnt, T value);
```
**Casos de uso**
```cpp
    size_t n = 0;
    int value = 0;
    cin >> n;
    cin >> value;
    vector<int> v1(n);
    for (auto &item: v1)
        cin >> item;
    increase_values(v1, value);
    auto current = begin(v1);
    cout << *current++;
    while(current != end(v1))
        cout << " " << *current++;
    cout << endl;
```

## Question #3 - Buscar números primos (5 points)

Elaborar la función **`get_primes`** que utilizando concurrencia genere una colección de números primos entre **`start`** y **`stop`** (sin incluir `stop`) y que los
almacene en un contenedor. El programa deberá asegurarse que los números sean almacenados en orden.
```cpp
template <typename T, template<typename ...> class Container>
void get_primes(Container<T>& cnt, T start, T stop);
```
**Casos de uso**
```cpp
    int first = 0;
    int last = 0;
    cin >> first >> last;
    vector<int> primes;
    get_primes(primes, first, last);
    auto current = begin(primes);
    cout << *current++;
    while(current != end(primes))
        cout << " " << *current++;
    cout << endl;
```

## Question #4 - single link list thread-safe (5 points)

Basado en el siguiente linked link:  

https://replit.com/@RubenDemetrioDemetrio/poo2singlelinkedlist#linked_list.h

Modificarlo lo que sea necesario para que permita soportar `pop_front` y `push_front` de valores concurrentemente.

**NOTA:** El `std::mutex` debera ser agregado dentro del `linked_list_t`

**Casos de uso**
```cpp
    // Linked list
    linked_list_t<int> ll;

    // Hilos
    vector <thread> vhilos(nhilos);

    // cantidad
    int n = 0;
    cin >> n;
    for (int i = 0; i < nhilos - nhilos/4; ++i) {
        vhilos[i] = thread([&ll, i] { ll.push_front(i); });
    }
    for (int i = 0; i < nhilos/4; ++i) {
        h = thread([&ll] { ll.pop_front(); });
    }
    cout << ll.size() << endl;
```

