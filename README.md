# Distribución de Camisetas

Este programa implementa un algoritmo de backtracking para distribuir un número dado de camisetas entre un grupo de voluntarios, respetando las preferencias de talla de cada uno.

## Requisitos

Para compilar y ejecutar este proyecto, se necesita tener un compilador compatible con C++ y un entorno de desarrollo configurado.

## Instrucciones de Uso

1. **Clonar el Repositorio:** Clona este repositorio en tu máquina local.

    ```bash
    git clone https://github.com/PepeGdlT/BackTracking_AED2.git
    ```

2. **Compilar el Proyecto:** Abre una terminal, navega hasta el directorio del proyecto y compila el código.

    ```bash
    g++ -o programa main.cpp
    ```

3. **Ejecutar el Programa:** Ejecuta el programa compilado y sigue las instrucciones para ingresar el número de casos, el número de camisetas y las preferencias de talla de los voluntarios.

    ```bash
    ./programa
    ```

## Formato de Entrada

El programa espera el siguiente formato de entrada para cada caso:

- **Línea 1:** Número de camisetas disponibles.
- **Línea 2:** Número de voluntarios.
- **Líneas 3 a M+2:** Preferencias de talla de cada voluntario, donde cada línea contiene dos tallas separadas por espacio.

Ejemplo de entrada para un caso:
```bash
30
3
XS L
M XXL
S M
```

## Formato de Salida

Para cada caso, el programa imprimirá "YES" si es posible distribuir las camisetas según las preferencias de los voluntarios, o "NO" en caso contrario.

## Contribuir

Las contribuciones son bienvenidas. Si tienes ideas para mejorar el proyecto, por favor abre un issue para discutir lo que te gustaría cambiar.

## Licencia

[MIT License](https://opensource.org/licenses/MIT)

