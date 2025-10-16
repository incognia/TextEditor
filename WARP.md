# Configuración Warp - TextEditor

Este archivo documenta las configuraciones específicas del proyecto TextEditor para su uso con Warp (Agentic Development Environment).

## Estructura del Proyecto

```
TextEditor/
├── WARP.md                      # Este archivo (configuración del proyecto)
├── .warp/                       # Configuración local de Warp
│   ├── rules/
│   │   └── COMMITTING.md       # Reglas de commits
│   ├── cot/
│   │   └── committing.md       # Workflow de commits
│   └── README.md               # Guía de la estructura .warp
├── src/                         # Código fuente
├── tests/                       # Pruebas
├── CHANGELOG.md                # Historial de cambios
└── README.md                   # Documentación del proyecto
```

## Reglas Locales

### `.warp/rules/COMMITTING.md`

Define las reglas de commits para TextEditor con énfasis en:

- **Commits Convencionales** en inglés internacional
- **CHANGELOG.md** en español mexicano con fechas CST (UTC-6)
- **Atomicidad**: cada commit representa un cambio único
- **Ámbitos específicos del proyecto**: ui, editor, parser, lexer, file, config, terminal

**Ubicación**: `.warp/rules/COMMITTING.md`

## Workflows automatizados (CoT)

### `.warp/cot/committing.md`

Workflow paso a paso para realizar *commits* siguiendo las reglas locales:

1. **Validación** de identidad SSH y configuración Git
2. **Análisis** de cambios con `git status`
3. **Cálculo** de fecha CST para CHANGELOG
4. **Actualización** de CHANGELOG.md
5. ***Commits* atómicos** con mensajes convencionales
6. **Envío** simple y verificación

**Ubicación**: `.warp/cot/committing.md`

**Uso**: `aplica .warp/cot/committing.md`

## Identidad Git Recomendada

Para este proyecto personal, usar la identidad personal con clave ed25519:

```bash
git config user.name "Rodrigo Álvarez"
git config user.email "incognia@gmail.com"
git config core.sshCommand "ssh -i ~/.ssh/id_ed25519 -o IdentitiesOnly=yes"
```

**Nota importante:** Se utiliza ed25519 en lugar de RSA para mayor seguridad. La clave está en `~/.ssh/id_ed25519`.

## Tipos de commits esperados en TextEditor

### Frecuentes

- **feat(ui):** cambios en interfaz de usuario
- **feat(editor):** funcionalidad principal del editor
- **fix(parser):** correcciones en análisis sintáctico
- **fix(lexer):** correcciones en tokenización

### Ocasionales

- **docs:** cambios en documentación
- **refactor:** reorganización de código
- **test:** adición de pruebas
- **perf:** mejoras de rendimiento

## Ejemplos de commits

### Bien formados

```
feat(ui): add syntax highlighting panel

Implement a new panel showing syntax tokens for the current line.
Users can toggle it via Ctrl+Shift+H.

Refs: #42
```

```
fix(parser): handle escaped quotes in strings
```

```
docs: update build instructions for macOS
```

### Mal formados (evitar)

```
updated code
```

```
feat
```

## Procedimiento de commit

1. **Hacer cambios** en el código
2. **Ejecutar CoT**: `aplica .warp/cot/committing.md`
3. El workflow:
   - Valida la configuración SSH
   - Analiza los cambios
   - Actualiza CHANGELOG.md automáticamente
   - Realiza *commits* atómicos
   - Envía cambios
   - Verifica con git log

## Referencia rápida

```bash
# Ver configuración actual (incluyendo SSH con ed25519)
git config --list | grep user\.

# Verificar clave SSH (ed25519)
git config core.sshCommand

# Calcular fecha CST
TZ=America/Mexico_City date +"%Y-%m-%d"

# Ver últimos commits
git --no-pager log --oneline -10

# Ver estado del repositorio
git status

# Ver cambios antes de commit
git --no-pager diff --staged
```

## Referencias

- [Commits Convencionales](https://www.conventionalcommits.org/en/v1.0.0/)
- `.warp/rules/COMMITTING.md` - Reglas completas
- `.warp/cot/committing.md` - Workflow de commits
- `.warp/README.md` - Guía de estructura .warp
- `CHANGELOG.md` - Historial del proyecto

---

*Configuración del proyecto TextEditor - Personal*
*Creado: 2025-10-16*
