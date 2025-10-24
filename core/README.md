# TextEditor Core - File Manager

Editor de texto básico en C++ con operaciones CRUD (Create, Read, Update, Delete) para archivos de texto.

## Estructura

```
core/
├── include/
│   └── file/
│       └── FileManager.h          # Interfaz de la clase FileManager
├── src/
│   └── file/
│       └── FileManager.cpp        # Implementación de FileManager
├── main.cpp                       # Programa principal con menú interactivo
├── Makefile                       # Sistema de compilación
├── CMakeLists.txt                # Configuración CMake (opcional)
└── build/
    └── bin/
        └── texteditor            # Ejecutable compilado
```

## Compilación

```bash
make
```

Para recompilar desde cero:

```bash
make rebuild
```

Para limpiar artefactos de compilación:

```bash
make clean
```

## Uso

### Ejecutar el programa

```bash
./build/bin/texteditor
```

O directamente con make:

```bash
make run
```

### Menú interactivo

El programa presenta un menú con las siguientes opciones:

```
=== TextEditor CRUD File Manager ===
1. Create a new file
2. Read a file
3. Update a file
4. Delete a file
5. Check if file exists
6. Read file by lines
7. Append to file
0. Exit
====================================
```

### Operaciones disponibles

#### 1. Create a new file
Crea un archivo nuevo con contenido opcional.
- Ingresa la ruta del archivo
- Ingresa el contenido (presiona Enter dos veces para finalizar)

#### 2. Read a file
Lee y muestra el contenido completo de un archivo.

#### 3. Update a file
Actualiza/sobrescribe el contenido de un archivo existente.
- Ingresa la ruta del archivo
- Ingresa el nuevo contenido (presiona Enter dos veces para finalizar)

#### 4. Delete a file
Elimina un archivo después de confirmación.

#### 5. Check if file exists
Verifica si un archivo existe en el sistema.

#### 6. Read file by lines
Lee un archivo y lo muestra línea por línea con numeración.

#### 7. Append to file
Agrega contenido al final de un archivo existente sin sobrescribir.
- Ingresa la ruta del archivo
- Ingresa el contenido a agregar (presiona Enter dos veces para finalizar)

#### 0. Exit
Sale del programa.

## Ejemplo de uso

```bash
$ ./build/bin/texteditor

Welcome to TextEditor Core - File Manager
Basic CRUD Operations Demo

=== TextEditor CRUD File Manager ===
1. Create a new file
2. Read a file
3. Update a file
4. Delete a file
5. Check if file exists
6. Read file by lines
7. Append to file
0. Exit
====================================
Choose an option: 1
Enter filepath: test.txt
Enter content (press Enter twice to finish):
Hello, World!
This is a test file.

✓ File created successfully!

Choose an option: 2
Enter filepath: test.txt

--- File Content ---
Hello, World!
This is a test file.

--- End of File ---
```

## Características

- ✅ Crear archivos de texto con contenido
- ✅ Leer archivos completos
- ✅ Actualizar/sobrescribir contenido
- ✅ Eliminar archivos con confirmación
- ✅ Verificar existencia de archivos
- ✅ Leer archivos línea por línea
- ✅ Agregar contenido al final de archivos
- ✅ Manejo de errores
- ✅ Interfaz interactiva amigable

## Requisitos

- g++ con soporte C++17 o superior
- make
- Sistema operativo: Linux, macOS, Windows (con MinGW)

## Notas

- Para ingresar contenido multilínea, presiona Enter dos veces para finalizar
- El programa usa rutas relativas o absolutas según lo especificado
- Se valida la existencia de archivos antes de operaciones de lectura/actualización
- La eliminación de archivos requiere confirmación (y/n)

## Licencia

GPL-3.0 - Ver LICENSE en la raíz del proyecto.
