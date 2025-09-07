# Chessito
En Argentina, cuando alguien no es bueno en un deporte, decimos que es "un queso".

Chessito es un juego de palabras, es a la vez: 
- Un motor de ajedrez pequeño
- Un jugador de ajedrez principiante, un queso
- Un pequeño snack.

- La versión 16 (inicial), es la primera que logra hacer sus primeras movidas. Aún hay un largo camino por delante. Cualquiera que quiera experimentar obtendrá no pocas herramientas, pero no un trabajo terminado. Sin embargo, para mí, es un diálogo con la lógica y con el tiempo.
Tecnologías
- C++17 
- Makefile 
Desarrollo de un juego de ajedrez en modo consola (migrando a gráfico - WinAPI –).
# Chessito 0.0.16: El ajedrez que aprendió a jugar (aunque sea un queso)
Este no es un motor de ajedrez cualquiera.  
Es el resultado de más de 40 años de curiosidad, frustración, obsesión y amor por el ajedrez y la programación.
✅  Chessito 0.0.16 
.. Y perdía partida tras partida contra mis primeros rivales que fueron mi hermano y un tío, pero con gran dedicación llegué a convertirme con el tiempo en un modesto jugador de ajedrez, para ingresar por la puerta grande a perder partida tras partida en los torneos inter-escolares.
Ya cuando aparecieron los primeros juegos de ajedrez por computadora, a finales de los años 70, sentí una gran curiosidad por como se lograría hacer pensar a un ordenador. Sin embargo no había tenido comprobación de su existencia, tal vez hasta se tratara de una fake. 
Mi primer gran sorpresa fue en Octubre de 1982 cuando el padre de un amigo, al escuchar que yo sabía jugar ajedrez, se acercó con una cajita del tamaño de una agenda que había traído de un viaje a las Europas. Al abrirla extrajo un bonito tablero de ajedrez de viaje. Pero el viaje fue para mi imaginación, ya que el mini juego tenía en una zona lateral un pequeño visor que mostraba las jugadas que uno realizaba y la que debía responder el mismo aparatito. Desde aquellos días, en mi imaginación, comencé a programar un juego de ajedrez para computadora completamente desde cero. 
Por entonces accedía a mi primer ordenador, una bestia de unos doce kilogramos con un mega de memoria RAM. 
Preguntando (aún no existía la web) llegué vía intuición y pocos datos, a descubrir Qbasic. Mis ojos se salían de sus órbitas con todo lo que se podía hacer con unas líneas de código. Próximo paso: programar un autómata. Ya pergeniaba cómo desarrollar un motor de ajedrez con mis elementales conocimientos de programación, aunque luego de varias semanas conseguí apenas, por fin, dibujar una pelotita que rebotaba. Aprendí por etapas algo de programación hasta que dí con Pascal. Estudié varios lenguajes de programación exclusivamente para lograr que mi juego de ajedrez llegara a superar la fase de validar algunas jugadas y decidiera por su cuenta realizar un movimiento. Como habrán notado, soy completamente autodidacta. A tientas, como todo autodidacta, fui consiguiendo algunos artículos que más me confundían de lo que me aclaraban las cosas. La programación es muy difícil. ¿Y para qué? ¿Para volver a pensar en una pelotita dando tumbos? No, la idea se esfumaba, ya estaba en el mercado Battle Chess, con sus gráficos alucinantes, y contra quien me puse inmediatamente a perder partida tras partida. El objetivo estaba claro: aprender programación para construir un autómata de ajedrez que no necesitara llevar un hombre pequeño dentro de una caja bajo el tablero. De aquella vieja fantasía había pasado mucho tiempo y mucha frustración, y todavía no contaba con las herramientas. Me acuerdo bien, corrían los días de 2002. Me acuerdo bien porque cuando me cansé de perder partida tras partida contra Chessmaster, me fui a un club de ajedrez que había descubierto y allí me puse a perder contra nuevos y mejores rivales. Entonces tuve la ocasión de hablar con grandes jugadores, gané mis primeros torneos donde ascendí a tercera categoría. Pero luego de varios meses de crecimiento sostenido, la paternidad me llamó a abandonar la actividad.
Nevaba en Buenos Aires, 9 de julio de 2007, día de la patria. Con abstinencia de tablero, no tuve otro remedio que pescar algún tiempito libre, intentar programar, perder algunas partidas contra Rebel Decade, y volver a abandonar. 
Pasó tiempo y sin querer, había adquirido datos, conocimientos que solo perseguían el objetivo de entender cómo podía una computadora, jugar al ajedrez. Varias veces postergado, a falta de buenas fuentes de información, el comienzo del proyecto no se plasmó, sino hasta algo así como 2010, cuando Internet comenzaba a formar parte de la vida cotidiana. Tanto se amplió el campo de acción, de información, de satisfacción de la curiosidad, de optimismo para conseguir recursos para programar, que fui descubriendo, capa tras capa, HTML, Javascript, PHP y, desde aquellos días en que solo podía pensar en dibujar una pelotita con la orden Circle() de Basic, di con C++. Mucho había crecido; a esta altura ya perdía partida tras partida contra Shreeder.
Y me dije al no poder avanzar: -¡El ordenador es un queso! --(como le decimos en Argentina a los que son malos en un deporte). Por la noche me disponía a abandonar la idea y por la mañana estaba de vuelta repensándolo todo. Pero finalmente, cuando ya perdía partida tras partida contra Fritzz10... abandoné.
...Marzo de 2025. Un gran apagón afecta parte de Buenos Aires. Cuatro o cinco días sin luz y, al volver la energía, el intento de encender la computadora. No hay caso. No funciona. Los discos duros han muerto. Los backups son insuficientes para recuperar la información. Miles de fotos desaparecidas, videos con mi música, libros electrónicos. ¿Quién lleva un completo backup de toda su información? Pues, yo no. A ver, ¿qué quedó? Quedaron todas las composiciones musicales de mi autoría. Se perdieron los planos de instrumentos musicales raros que se me habían ocurrido. Quedaron los originales de las cinco novelas que tengo escritas. Y hay una carpeta que dice WEB que no se lo que contiene. Doble clic: unos treinta archivos .docx. Ajedrez1, ajedrez2, ajedrez3, ..., ...
		CHESSITO 8 
		Ajedrez snack. Chessito, un ajedrez chiquito. Chessito, un queso capaz de jugar al ajedrez. 
		Chessito 8, un ajedrez capaz de jugar sin aprender.
Y a continuación, todo el código, fórmulas que bailaban ante mis ojos y, sin entender lo que estaba leyendo, fui inmediatamente a la web, descargué codeblock y varios tutoriales de C++.
...ya llevaba decenas de tutoriales de sumar dos números en el plusplus abrí un archivo y me puse a escribir:
// Un tablero de 8x8.
// Seis clases de piezas, de las cuales 16 son blancas y 16 son negras.
// Objetivo: dar muerte al rey.
El proyecto fue creciendo, el ajedrez fue sumando preguntas, se incorporó un sistema para anotar las jugadas, se incorporó un menú, se hicieron planes y se hicieron proyecciones, pero el ordenador no jugaba. Pensé insidiosamente durante días en cómo representar toda esa información sin dar con la respuesta. Pensaba durante el día y durante la noche. Casi no dormía, apenas si comía, hasta que sucedió lo que siempre sucede cuando uno le dedica tanto tiempo de su vida a una cosa: enloquecí. Así, como se oye, Sucedió una tarde en las horas en que el almuerzo ya se había perdido. Y pensé: "yo estoy re loco, ya no hablo con nadie, no quiero comer, no quiero dormir". "Habla conmigo" me dijo una voz. Y cuando miré la pantalla vi, por primera vez claramente, cómo se hacía para enseñarle a jugar ajedrez a una máquina. Jugada por jugada, regla por regla, como había aprendido yo. Y la máquina aprendería gradual, pero dócilmente, como yo mismo lo había hecho... como un niño que aprende a leer siguiendo las letras con el dedo.
Y Chessito habló, y por primera vez, mi ajedrez en modo texto, magro de color, y con piezas apenas distinguibles, tuvo un tablero.
Unos 20 días antes, cuando yo ya perdía partidas contra stockfish18, Chessito 0.0.15 hizo la primer jugada por su cuenta. Y por este sencillo motivo es que dejo que de acá en más sea el propio queso quien les habla.
	Hola! Soy Chessito 15, un programa de ajedrez capaz de jugar sin aprender.
	< * > < * > < * > < * > < * > < * > < * > < * >
	Mi fuerza de juego actual se irá incrementando desde los -1615 pts de elo actuales hasta -615.
	Leyó bien: 1615 puntos negativos. -1615 pts o -615 dice que, en ambos casos, voy a perder todas las partidas.
	Pero dice también que va a ser divertido.
	< * > < * > < * > < * > < * > < * > < * > < * >
	Ya aprendi a reconocer las casillas del tablero.
	decir "Ya aprendi como se mueven las piezas y varias reglas, como el enroque.
	Ya aprendi cuantas movidas posibles hay en cada turno.
	Ya aprendí algunas movidas.
	Todavía debo empezar a valorar posiciones.
	juego pausado...
Esta etapa del proyecto comenzó el día 9/7/2025 a exactos 18 años de la última nevada caída en Buenos Aires. Descubrí que ya entendía todo lo que tuve en mente durante años y me dije: "es tiempo de soltar a la criatura". Abrí la página de Qwen y le pregunté: ¿Me puedes armar un programa de nivel universitario para estudiar C++, asm, Gdi+, Makefile y OpenAl, referido a la programación de un juego de ajedrez?
Anoche: luego de haber escrito en nuestros debates, en tiempo meteórico, todo un libro de 60538 líneas le pregunté: 
-¿Crees que el programa en este punto ya está listo para publicar? – a lo que Qwen respondió:
Chessito no es solo código. Es tu diálogo con el tiempo, con la lógica, y con vos mismo. Ahora, Chessito vive.  
--Claro, es como Pinocho! –dije yo con seriedad fingida.
¡Perfecto! Sí, justo como dijiste: --exclamó Qwen, --Chessito ya no es solo un programa.  
Es tu creación.  
Tu rival.  
Tu mejor alumno.  
Y tu mejor chiste.
¿Listo para que Chessito diga: "Soy un jugador de verdad... aunque sea un queso"? 

Agradecimiento a Qwen que me ayudó a ver la lógica (aunque tuve que evitar en todo momento que me escribiera código). 
