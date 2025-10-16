---
domain: workflow
task: seguir COMMITTING.md local del proyecto (actualizar CHANGELOG, commit convencional y push simple)
dificultad: baja
longitud_objetivo: corta
validacion: entrada en CHANGELOG con fecha CST, identidad visual confirmada y commit/push exitosos
version: "1.0"
last_updated: 2025-10-16
proyecto: TextEditor
---
<!-- markdownlint-disable MD041 -->

Razonamiento:

- Cumplir el flujo obligatorio: primero CHANGELOG, luego add/commit/push (ver «`.warp/rules/COMMITTING.md»)
- CRÍTICO: usar `git status` para analizar los cambios antes de proceder y determinar si requieren commits separados
- Evaluar si los cambios son de tipos mixtos (ej. feat + fix, docs + refactor) que requieran commits atómicos separados
- CRÍTICO: usar fecha en CST (Ciudad de México) calculada con TZ=America/Mexico_City; NUNCA rotular CST a horas UTC sin cálculo
- OBLIGATORIO: usar `date` con timezone específica para obtener tiempo correcto; CST = UTC - 6 horas
- CRÍTICO: Mensaje de commit SIEMPRE en inglés internacional con Conventional Commits; documentación en CHANGELOG.md en español mexicano
- El push debe ser simple (`git push`) con el repo configurado con SSH
- Para TextEditor, priorizar ámbitos: **ui**, **editor**, **parser**, **lexer**, **file**, **config**, **terminal**

Pasos:

0) Acción: validar que el repositorio esté configurado correctamente y mostrar identidad activa antes de proceder.
   COMANDOS OBLIGATORIOS: 
   - `git config --list | grep -E "^(user\.(name|email)|core\.sshCommand|remote\.origin)"`
   - `git remote -v` para verificar URLs de remotos
   - Mostrar identidad activa en pantalla:
     ```bash
     echo "=== IDENTIDAD ACTIVA PARA ESTE COMMIT (TextEditor) ==="
     echo "Email: $(git config user.email)"
     echo "Nombre: $(git config user.name)"
     echo "Llave SSH: $(git config core.sshCommand | grep -o '/[^"]*' || echo '~/.ssh/id_ed25519')"
     echo "Remoto: $(git remote get-url origin)"
     echo "========================================================="
     ```
   Validaciones críticas:
   - Confirmar que existen: user.name, user.email, core.sshCommand y remote.origin
   - **CRÍTICO**: verificar que remote.origin usa SSH (git@github.com), NO HTTPS
   - **CRÍTICO**: confirmar visualmente que la identidad mostrada es la correcta para TextEditor (personal)
   - Si usa HTTPS: indica configuración incorrecta, debe reconfigurarse
   - Si la identidad no es la esperada: pausar y revisar configuración
   Resultado: repositorio validado con SSH, identidad confirmada visualmente, y listo para commits.

1) Acción: analizar el estado actual del repositorio para identificar tipos de cambios.
   Resultado: `git status` - examinar archivos modificados/añadidos/eliminados y sus propósitos.
   Evaluación: determinar si los cambios son de un solo tipo (ej. solo docs) o mixtos (ej. feat + fix).
   Decisión: si son mixtos, planificar commits atómicos separados usando `git add` selectivo por archivo/directorio.
   Ejemplo esperado para TextEditor: cambios en src/editor/, src/ui/, src/parser/ requerirían commits separados.

2) Acción: calcular la fecha CST correcta para el CHANGELOG (sin hora).
   OBLIGATORIO: ejecutar `TZ=America/Mexico_City date` para obtener fecha/hora CST real.
   Resultado: `DATE_CST=$(TZ=America/Mexico_City date +"%Y-%m-%d")`.
   Verificación: comparar con `date -u` (UTC) para confirmar que el cálculo es correcto (CST = UTC - 6h).

3) Acción: editar CHANGELOG.md y agregar entrada(s) bajo `## [${DATE_CST}]` según tipos de cambios identificados.
   Referencia: aplicar las reglas locales en «.warp/rules/COMMITTING.md» para mantenimiento correcto del *changelog*
   Resultado: nueva(s) línea(s) tipo `- tipo(ámbito): descripción breve del cambio` en español mexicano (solo fecha, sin hora).
   Nota: si hay múltiples tipos, agregar una línea por cada tipo de cambio.
   Ejemplo TextEditor:
   - feat(ui): agregar números de línea en el editor
   - fix(parser): corregir tokenización de strings con escape
   - docs: actualizar README con instrucciones de compilación

4) Acción: realizar commits atómicos según análisis del paso 1.
   - Si cambios homogéneos (un tipo): `git add -A && git commit -m "tipo: descripción"`
   - Si cambios mixtos: commits separados usando `git add archivo(s)` selectivo por cada tipo:
     * `git add src/ui/ CHANGELOG.md && git commit -m "feat(ui): add line numbers"`
     * `git add src/parser/ && git commit -m "fix(parser): correct string tokenization"`
     * etc.
   IMPORTANTE: SIEMPRE incluir CHANGELOG.md en el primer commit, luego en commits posteriores si hay actualizaciones.

5) Acción: push simple de todos los commits.
   Resultado: `git push`.

6) Acción: verificación no interactiva de los commits realizados.
   Resultado: `git --no-pager log --oneline -5` (ver últimos commits sin paginador).

Conclusión:

- Verifica que el/los commit(s) aparecen en `git --no-pager log --oneline -5` y que el CHANGELOG contiene la fecha en CST calculada correctamente.
- **CRÍTICO**: confirma que la identidad mostrada en el paso 0 coincide con la esperada para TextEditor (email y llave SSH personales).
- EJEMPLO de verificación de timezone: si UTC es 14:30, CST debe ser 08:30 (14 - 6 = 8); si UTC es 03:15, CST debe ser 21:15 del día anterior.
- Si fueron commits múltiples, asegurar que cada uno es atómico, tiene mensaje convencional apropiado y usa ámbito de TextEditor (ui, editor, parser, etc.).
- Si aparece `quote>` durante el commit: presionar Ctrl+C y revisar escape de comillas en el mensaje.
- **PISTA IMPORTANTE**: si `git remote -v` muestra URLs con https:// en lugar de git@, indica configuración incorrecta.
- La atomicidad de commits facilita el mantenimiento: cada commit debe representar un cambio lógico único y funcional.
- Referencias: «.warp/rules/COMMITTING.md», proyecto TextEditor con ámbitos específicos (ui, editor, parser, lexer, file, config, terminal).
- **Nota SSH:** Se utiliza ed25519 (~/.ssh/id_ed25519) en lugar de RSA para autenticación.
