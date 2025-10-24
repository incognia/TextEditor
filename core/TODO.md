# TODO - TextEditor Core

Roadmap para convertir el core en una biblioteca compartida utilizable por las GUIs nativas.

## Estado actual

- ✅ FileManager con operaciones CRUD básicas implementado
- ✅ Compilación como biblioteca estática (`libtexteditor_core.a`)
- ✅ CLI de prueba funcional (`main.cpp`)
- ✅ Sistema de compilación con Makefile y CMake

## Pendientes para biblioteca compartida

### 1. Refactorizar arquitectura de biblioteca

**Objetivo:** Convertir el core en biblioteca compartida (`.so`/`.dll`/`.dylib`) utilizable por GUIs nativas.

**Tareas:**

- [ ] Mover `main.cpp` a directorio separado (`tools/cli/` o `examples/`)
- [ ] Crear header API público (`include/TextEditorAPI.h` o `include/TextEditorCore.h`)
- [ ] Definir interfaz C para compatibilidad multiplataforma (opcional pero recomendado)
- [ ] Modificar CMakeLists.txt para compilar como shared library
- [ ] Configurar exportación de símbolos (visibility attributes en GCC/Clang, `__declspec` en MSVC)

### 2. Diseñar API pública

**Objetivo:** Exponer interfaz limpia y estable para que las GUIs la consuman.

**Tareas:**

- [ ] Definir funciones públicas del API (inicialización, creación/lectura/actualización/borrado)
- [ ] Ocultar detalles de implementación (clases internas privadas)
- [ ] Documentar API con comentarios Doxygen
- [ ] Crear header de versión (`TextEditorVersion.h`) con macros de versión

**Ejemplo de API propuesta:**

```cpp
// include/TextEditorAPI.h
namespace TextEditor {
    class CoreAPI {
    public:
        // Lifecycle
        static CoreAPI* initialize();
        void shutdown();
        
        // File operations
        bool createFile(const std::string& path, const std::string& content);
        std::optional<std::string> readFile(const std::string& path);
        bool updateFile(const std::string& path, const std::string& content);
        bool deleteFile(const std::string& path);
        
        // Buffer management (futuro)
        // Editor operations (futuro)
    };
}
```

### 3. Configurar sistema de compilación multiplataforma

**Objetivo:** CMake que compile correctamente en Linux, Windows y macOS.

**Tareas:**

- [ ] CMakeLists.txt con opción `BUILD_SHARED_LIBS`
- [ ] Configurar RPATH/RUNPATH en Linux
- [ ] Configurar install_name en macOS
- [ ] Configurar DLL export/import en Windows
- [ ] Crear CMake config files para que `platform/` encuentre la biblioteca
- [ ] Agregar targets de instalación (`make install`)

### 4. Separar CLI del core

**Objetivo:** El CLI debe ser un consumidor más del API, no parte del core.

**Opciones:**

**Opción A: Tools directory (recomendado)**
```
tools/
└── cli/
    ├── main.cpp
    ├── CMakeLists.txt
    └── README.md
```

**Opción B: Examples directory**
```
examples/
└── cli/
    ├── main.cpp
    ├── CMakeLists.txt
    └── README.md
```

**Tareas:**

- [ ] Crear directorio `tools/cli/` o `examples/cli/`
- [ ] Mover `main.cpp` al nuevo directorio
- [ ] Crear CMakeLists.txt que linke contra `libtexteditor_core`
- [ ] Actualizar README principal con nueva estructura
- [ ] Actualizar `core/README.md` para reflejar uso como biblioteca

### 5. Preparar para integración con GUIs

**Objetivo:** Las GUIs nativas deben poder usar el core fácilmente.

**Tareas:**

- [ ] Crear ejemplo mínimo de uso del API en C++ puro
- [ ] Documentar proceso de linkeo para cada plataforma:
  - Linux: `-ltexteditor_core` con CMake `find_package(TextEditorCore)`
  - Windows: Link contra `TextEditorCore.lib` + copiar `TextEditorCore.dll`
  - macOS: Framework o dylib linkeo dinámico
- [ ] (Opcional) Crear bindings C para interoperabilidad con C#/Swift
- [ ] Configurar pkg-config (`.pc` file) para Linux

### 6. Testing y validación

**Objetivo:** Asegurar que el API funciona correctamente.

**Tareas:**

- [ ] Crear suite de pruebas unitarias (Google Test o Catch2)
- [ ] Probar compilación en las tres plataformas
- [ ] Validar que las GUIs pueden linkar correctamente
- [ ] Benchmark de rendimiento básico

## Estructura objetivo

```
TextEditor/
├── core/                          # Biblioteca compartida
│   ├── include/                   # API pública
│   │   ├── TextEditorAPI.h
│   │   ├── TextEditorVersion.h
│   │   └── file/
│   │       └── FileManager.h
│   ├── src/                       # Implementación privada
│   │   └── file/
│   │       └── FileManager.cpp
│   ├── CMakeLists.txt            # Compila libTextEditorCore.so/.dll/.dylib
│   ├── Makefile                  # Build directo (desarrollo)
│   ├── README.md
│   └── TODO.md                   # Este archivo
│
├── tools/cli/                    # CLI de prueba (consumidor del API)
│   ├── main.cpp
│   ├── CMakeLists.txt
│   └── README.md
│
├── platform/                     # GUIs nativas (consumen el API)
│   ├── linux/                    # Qt6/GTK4 → link contra libTextEditorCore.so
│   ├── macos/                    # Swift → link contra libTextEditorCore.dylib
│   └── windows/                  # C#/WPF → P/Invoke a TextEditorCore.dll
│
└── shared/                       # Recursos compartidos
    ├── icons/
    ├── localization/
    └── themes/
```

## Prioridades

### Corto plazo (Sprint 1)
1. Mover `main.cpp` a `tools/cli/`
2. Crear header API público básico
3. Modificar CMakeLists.txt para shared library

### Medio plazo (Sprint 2)
4. Documentar API con Doxygen
5. Crear ejemplo de uso mínimo
6. Testing básico

### Largo plazo (Sprint 3)
7. Bindings C para interoperabilidad
8. Integración con primera GUI nativa (Linux/Qt6)
9. Benchmark y optimización

## Referencias

- [Conventional Commits](https://www.conventionalcommits.org/)
- [CMake shared libraries](https://cmake.org/cmake/help/latest/command/add_library.html)
- [Symbol visibility in GCC](https://gcc.gnu.org/wiki/Visibility)
- Proyecto README: `../README.md`
- Reglas de commits: `../.warp/rules/COMMITTING.md`

---

*Última actualización: 2025-10-24*
