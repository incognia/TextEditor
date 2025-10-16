# Configuración Warp del Proyecto

Este directorio contiene todas las configuraciones específicas del proyecto TextEditor para uso con Warp.

**📌 Nota:** La documentación principal está en `WARP.md` en la raíz del proyecto.

## Contenido

### `WARP.md` (en raíz del proyecto)
Archivo principal de configuración en la raíz que documenta:
- Estructura del proyecto
- Reglas locales aplicables
- Workflows disponibles
- Ejemplos y referencia rápida

**Ubicación**: `../WARP.md`

### `rules/`
Contiene las reglas de desarrollo específicas del proyecto:

- **`COMMITTING.md`** - Reglas completas de commits, CHANGELOG y flujo de trabajo
  - Formato de mensajes de commit (Conventional Commits)
  - Ámbitos específicos de TextEditor
  - Proceso obligatorio de actualización de CHANGELOG
  - Comandos git no interactivos recomendados

### `cot/`
Workflows automatizados (*Chain of Thought*) que implementan las reglas:

- **`committing.md`** - Flujo paso a paso para realizar *commits*
  - Paso 0: Validación de configuración SSH e identidad
  - Paso 1: Análisis de cambios pendientes
  - Paso 2: Cálculo de fecha CST
  - Paso 3: Actualización de CHANGELOG.md
  - Paso 4: Commits atómicos
  - Paso 5: Push
  - Paso 6: Verificación

## Cómo usar

### Aplicar un Workflow (CoT)

```bash
aplica .warp/cot/committing.md
```

### Consultar Reglas

```bash
# Ver reglas de commits
cat .warp/rules/COMMITTING.md

# Ver configuración general del proyecto
cat WARP.md
```

### Verificar Configuración Git

```bash
# Identidad del repositorio
git config --list | grep user\.

# Clave SSH ed25519
git config core.sshCommand

# Remoto SSH
git remote -v

# Fecha CST correcta
TZ=America/Mexico_City date +"%Y-%m-%d"
```

## Estructura de Directorios

```
TextEditor/
├── WARP.md                  # Configuración principal (en raíz)
└── .warp/
    ├── README.md            # Este archivo
    ├── rules/
    │   └── COMMITTING.md    # Reglas de commits
    └── cot/
        └── committing.md    # Workflow de commits
```

## Notas importantes

1. **Siempre actualizar CHANGELOG.md antes de hacer commit** - Es una regla crítica
2. **Usar CST (UTC-6)** - No UTC. Calcular con `TZ=America/Mexico_City date`
3. **Commits en inglés** - Los mensajes de commit van en inglés internacional
4. **CHANGELOG en español** - Las entradas del CHANGELOG van en español mexicano
5. **Atomicidad** - Cada commit debe representar un cambio único
6. **Usar SSH ed25519** - No HTTPS ni RSA. La configuración debe usar SSH con clave ed25519 (~/.ssh/id_ed25519)

## Referencias rápidas

- [Commits Convencionales](https://www.conventionalcommits.org/en/v1.0.0/)
- Zona horaria: CST = UTC - 6 horas
- Ámbitos del proyecto: ui, editor, parser, lexer, file, config, terminal
- **Clave SSH:** ed25519 (~/.ssh/id_ed25519)

---

*Estructura de Warp para TextEditor*
