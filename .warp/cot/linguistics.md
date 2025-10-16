---
domain: writing
task: aplicar correctamente las reglas de LINGUISTICS.md al proyecto TextEditor
dificultad: media
longitud_objetivo: media
validacion: lista de hallazgos + correcciones propuestas alineadas a es_MX y reglas tipográficas
version: "1.0"
last_updated: 2025-10-16
proyecto: TextEditor
---
<!-- markdownlint-disable MD041 -->

Razonamiento:

- Regla principal: todo en español mexicano, sin calcos del inglés ni regionalismos ajenos (ver «.warp/rules/LINGUISTICS.md»)
- Recorrer de lo general a lo específico: dialecto/es_MX → evitar calcos → terminología específica de TextEditor → verbos → préstamos en cursiva → tipografía (títulos y mayúscula tras dos puntos) → comillas (texto vs código) → nomenclatura de archivos → odios especiales → tiempos verbales
- Producir hallazgos concretos y una versión corregida cuando aplique
- Para TextEditor: enfatizar términos de editor de texto, sintaxis, compilación

Pasos:

1) Acción: verificar dialecto y regionalismos.
   Resultado: marcar peninsularismos («fichero», «directorio»), otros regionalismos y reemplazar por es_MX («archivo», «carpeta»...)
   Enfoque TextEditor: revisar documentación de características de editor

2) Acción: evitar calcos del inglés frecuentes.
   Resultado: «hacer/ejecutar» (no «realizar»), «aplicar» (no «implementar»), «admitir» (no «soportar»), «ahora» (no «actualmente»), etc.
   Enfoque: documentación y comentarios del proyecto

3) Acción: normalizar terminología técnica específica de TextEditor.
   Resultado: verificar uso correcto de:
   - «Editor de texto»
   - «Resaltado de sintaxis»
   - «Analizador sintáctico» (vs «parser»)
   - «Tokenización»
   - «Deshacer/Rehacer»
   - «Búsqueda y reemplazo»

4) Acción: revisar verbos técnicos.
   Resultado: «compilar» (no «buildear»), «probar/poner a prueba» (no «testear»), «depurar» (no «debugear»), «confirmar cambios» (no «commitear»)

5) Acción: préstamos técnicos (cursiva).
   Resultado: cursiva en *commit*, *parser*, *lexer*, *pipeline*, *stack*

6) Acción: tipografía de títulos y encabezados.
   COMANDO OBLIGATORIO: `grep -n "^#" archivo.md` para listar TODOS los títulos H1-H6
   Validación: Revisar cada línea encontrada individualmente
   Resultado: estilo oración (primera palabra y nombres propios con mayúscula), sin punto final
   CRÍTICO: No marcar este paso como completo sin documentar cada título encontrado

7) Acción: comillas (texto vs código).
   Resultado: «» en texto; "" solo en comentarios de scripts/código

8) Acción: nomenclatura de archivos.
   Resultado: nombres en inglés internacional; Markdown en NOMBRES_EN_MAYUSCULAS.md

9) Acción: odios especiales (bloqueo explícito).
   Resultado: rechazar «fichero» (por «archivo»), «directorio» (por «carpeta»), verbos con -ear, mayúscula tras dos puntos, pluralizar siglas

10) Acción: tiempos verbales.
    Resultado: guías en segunda persona (imperativo); reportes en primera persona; evitar tercera impersonal

VERIFICACIÓN OBLIGATORIA (antes de completar):

- Ejecutar: `grep -n "^#" archivo.md` y documentar cada título encontrado
- Confirmar: ninguno usa "Título Con Cada Palabra En Mayúscula"
- Listar: todos los cambios de capitalización aplicados
- Validar: uso correcto de cursivas en préstamos técnicos (*parser*, *commit*, etc.)
- Verificar: corrección de todos los calcos del inglés identificados

Conclusión:

- Entregar: (a) lista de hallazgos y reemplazos propuestos; (b) fragmentos corregidos con comillas y mayúsculas adecuadas; (c) confirmación de que no hay títulos con mayúscula en cada palabra
- Referencias: «.warp/rules/LINGUISTICS.md», proyecto TextEditor con terminología de editor de texto
