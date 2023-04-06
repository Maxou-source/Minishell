#MINISHELL(🇬🇧)

Welcome to my Minishell github repository! Minishell is one of hardest and longest project at 42 (in the common core).
I did this project with my mate @Mousliiim.

The objective of this project is to recode a shell like Bash. A shell is the interface between the user and the computer core. We recoded this project in C. 
I did the execution part while Mouslim did the parsing, We also splitted differents tasks such as the builtins, the expand, the prompt and the tokenisation.

##Start the project on your computer

```bash
make && ./minishell
```

##Explanations of my work

Like I've mentioned before hand i took care if the execution! I will explain in this read me the basic mechanic of my execution!

Once the parsing is done, Mouslim sends me a structure table for each command. Each structure contains these 2 fundamental elements for each structure:
- a command in clear 
- a chained list containing in each node a file name and its associated redirection type
```C
typedef struct s_tab_struct
{
	// the command in clear
	char				**split_command;
	// the chained list
	t_list_mini			*head;

	// other variables used to build or exec
	char				**commands;
	int					type;
	int					prev_heredocs;
}						t_tab_struct;
```

The table of structure is contained in our other structure named t_global (yes i know it isn't a global but its named global). When I want to send a specific structure from the table of structure i will send the structure global along with the index of the structure tab_struct. 

For every command I create a pipe and send it as argument threw the function forking.
```C
while (++i < global->nb) // i is set at -1
{
	signal(SIGINT, SIG_IGN); // this ignores the CTRL+C in the execution
	pipe(global->link);
	forking(global, i);
    // where global is the structure t_global and i the index 
    // of the structure tab_struct I want to send over
}
```

The function ```forking``` makes a fork in which I will execute the command. In the just created child process, I am checking out where i need to write the command. 
```bash
ls | cat # this command will first write the command ls on the pipe and then cat the result on the standard output
```
The following code will check where the command needs to be written according to the index.
If I'm not on the first command the previous readable fd from the pipe becomes the standard input and if I am not on the last command the standard output will become the fd on which I can write. 
```C
	if (i != 0)
		dupnclose(glo->prev, STDIN_FILENO); // redirects STDIN on glo->prev and closes glo->prev
	if (i != (glo->nb - 1))
		dup2(glo->link[1], STDOUT_FILENO);
	close(glo->link[0]);
	close(glo->link[1]);
```
I need to thank @Mohazerro for comming up with this strategy and explaining it to me.


#MINISHELL  (🇫🇷)

Bienvenue sur repo github de Minishell! Minishell est l'un des projets les plus long et plus compliqué à 42 (à l'interieur du tronc commun).
J'ai réalisé ce projet avec mon mate @Mousliiim.

L'objectif de ce projet est de recoder un shell comme Bash. Un shell est une interface entre l'utilisateur et le noyau de l'ordinateur.
Je me suis occuper de l'execution pendant que Mouslim s'occupait du parsing. Nous nous sommes repartis d'autres taches comme les builtins, l'expand et la tokenisation.

##Demarrer le projet sur ton ordinateur

```bash
make && ./minishell
```

##Explications de mes taches réaliser

Comme je l'ai dit je me suis occuper de l'execution. Je vais vous expliquer dans ce ReadMe le fonctionnement basique de mon execution!

Donc une fois le parsing fini Mouslim m'envoie un tableau de structure contenant ces elements pour chaque structure.
- une commande en claire
- une liste chainee contenant pour chaque maillon un nom de fichier 

```C
typedef struct s_tab_struct
{
	// the command in clear
	char				**split_command;
	// the chained list
	t_list_mini			*head;

	// other variables used to build or exec
	char				**commands;
	int					type;
	int					prev_heredocs;
}						t_tab_struct;
```
I have to thank @Mohazerro for comming up with this strategy.

#MINISHELL  (🇩🇪)

Willkommen in meinem Minishell-Github-Repository! Minishell ist (im Common Core) eines der schwierigsten und längsten Projekte im 42 Programm. 
Ich habe dieses Projekt mit meinem Kumpel @Mousliiim gemacht.

Das Ziel dieses Projekts ist es, eine Shell, wie zum Beispiel “Bash”, umzucodieren. Eine Shell ist ein Interface zwischen dem Benutzer und dem CPU-Kern. Wir haben dieses Projekt in C umcodiert, wobei ich die Ausführung gemacht habe, während Mouslim das Parsing gemacht hat. Wir haben auch weitere Aufgaben wie die Builtins, die Erweiterung, die Prompts und die Tokenisierung aufgeteilt.

##Starten Sie das Projekt auf Ihrem Compute
