# Reglas de mensajes de *commit* y gestión de cambios - TextEditor

## 1. Filosofía principal

Un historial de *commits* bien estructurado es fundamental para el mantenimiento del editor de texto. Cada *commit* debe ser atómico, tener un propósito claro y un mensaje conciso que lo describa.

## 2. Formato del mensaje de *commit*

Utilizar la especificación de [Commits Convencionales](https://www.conventionalcommits.org/en/v1.0.0/).

### 2.1. Estructura general

```text
<tipo>[ámbito opcional]: <descripción>

[cuerpo opcional]

[pie opcional]
```

### 2.2. Tipos de *commit* (en orden de frecuencia esperada)

- **feat:** nueva funcionalidad del editor (comandos, características UI, etc.)
- **fix:** corrección de errores o bugs
- **refactor:** reestructuración de código sin cambiar funcionalidad
- **perf:** mejoras de rendimiento
- **test:** adición o corrección de pruebas unitarias
- **docs:** cambios en documentación (README, comentarios de código)
- **style:** formato de código, espacios en blanco (sin cambio de lógica)
- **build:** cambios en sistema de build, dependencias
- **ci:** configuración de CI/CD
- **chore:** mantenimiento general, actualizaciones de dependencias

**⚠️ IMPORTANTE:** Los archivos CoT (Chain of Thought) como `.warp/cot/committing.md` son documentos funcionales que definen workflows. Se clasifican como **`feat:`** (no `docs:`), ya que representan nueva funcionalidad del proyecto, no simple documentación.

### 2.3. Reglas del mensaje

- **Idioma:** redactar siempre en **inglés internacional**
- **Emojis:** no usar emojis
- **Descripción:** debe ser concisa, en imperativo y en minúsculas (ej. `feat: add line number display`)
- **Cuerpo:** opcional, para explicar el *qué* y el *porqué* del cambio
- **Pie:** opcional, para referencias a *issues* (`Refs: #123`) o cambios incompatibles (`BREAKING CHANGE:`)

### 2.4. Ámbitos comunes del proyecto

Cuando sea aplicable, usar ámbitos que reflejen la estructura del editor:

- **ui:** componentes de interfaz de usuario
- **editor:** lógica principal del editor
- **parser:** análisis sintáctico
- **lexer:** tokenización
- **file:** manejo de archivos
- **config:** configuración del aplicativo
- **terminal:** interacción con terminal

### 2.5. Ejemplos

#### Bueno

```text
feat(ui): add syntax highlighting for javascript

Implement tokenization and rendering of syntax-highlighted code
for JavaScript with support for keywords, strings, and comments.

Refs: #15
```

```text
fix(editor): correct cursor position after undo operation
```

#### Malo

```text
fix
```

```text
updated stuff
```

## 3. Flujo de trabajo y gestión de cambios

### 3.1. Actualización del `CHANGELOG.md` (CRÍTICO)

🔥 **REGLA CRÍTICA: SIEMPRE actualizar el archivo `CHANGELOG.md` ANTES de cada *commit*.**

**PROCESO OBLIGATORIO:**
1. **PRIMERO:** Actualizar `CHANGELOG.md` con los cambios realizados
2. **SEGUNDO:** Hacer `git add` de todos los archivos (incluyendo CHANGELOG.md)
3. **TERCERO:** Hacer `git commit`
4. **CUARTO:** Hacer `git push`

**⚠️ ADVERTENCIA:** Nunca hacer commit sin haber actualizado primero el CHANGELOG.md. Esta es una regla fundamental.

**Especificaciones del CHANGELOG.md:**

- **Idioma:** español mexicano
- **Zona horaria:** usar **CST de Ciudad de México (UTC-6)** para todas las fechas
- **Formato de fecha:** usar únicamente fecha sin hora en formato `[YYYY-MM-DD]` según CST
- **Título descriptivo:** usar el formato `## [YYYY-MM-DD]` para secciones de fecha
- **NO usar emojis** - mantener contenido limpio y profesional

**Comando para obtener fecha CST correcta:**

```bash
DATE_CST=$(TZ=America/Mexico_City date +"%Y-%m-%d")
echo "$DATE_CST"
```

- **Contenido mínimo:**
  - Fecha del cambio en formato `[YYYY-MM-DD]` según CST (UTC-6)
  - Tipo de cambio (coincidente con el prefijo del *commit*)
  - Breve descripción en español mexicano

### 3.2. Atomicidad de los *commits*

- **Un propósito por *commit*:** cada *commit* debe reflejar un cambio único y funcional
- **No mezclar tipos:** evitar combinar feat con fix en el mismo commit
- **Cambios pequeños:** dividir refactorizaciones grandes en commits lógicos

### 3.3. Asociación con tareas

- **Referencia a *issues*:** siempre que sea posible, asociar commits con su issue correspondiente en el pie del mensaje (`Refs: #123`, `Closes: #123`)

### 3.4. Push simplificado

Con el repositorio configurado correctamente (identidad SSH):

```bash
git push
```

### 3.5. Comandos git no interactivos

**⚠️ IMPORTANTE:** Siempre usar comandos no interactivos para evitar paginadores.

```bash
# Ver historial de commits (no interactivo)
git --no-pager log --oneline -10
git --no-pager log --oneline -5

# Ver diferencias (no interactivo)
git --no-pager diff
git --no-pager diff --staged

# Ver estado
git status

# Otros comandos
git --no-pager show HEAD
git --no-pager branch -v
```

### 3.6. Solución de problemas comunes

#### Problema: `quote>` en git commit

**Síntoma:** Al ejecutar `git commit -m "mensaje"` aparece `quote>`.

**Soluciones:**

```bash
# BIEN: escapar comillas internas
git commit -m "fix: correct \"user\" validation"

# MEJOR: usar comillas simples
git commit -m 'fix: correct "user" validation'
```

---

*Reglas del proyecto TextEditor - Personal*
*Clave SSH: ed25519 (~/.ssh/id_ed25519)*
