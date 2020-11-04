---
author: 
    - "Maxime AYRAULT"
title: | 
	   | Reconfiguration d’Architectures pour l’Amélioration de la Résilience des Véhicules Connectés
	   |
short-title : |
              | Soutenance de mi-parcours
			  |
subtitle: | 
	      | Soutenance de mi-parcours
          | 
		  | Encadrants de Thèse :
		  | Etienne Borde 
		  | Ulrich Kühne 

date: "6 Novembre 2020"

theme: CambridgeUS
colortheme: dolphin

toc: no
toc-depth: 2
//toc-title: Sommaire


header-includes:
    - \usepackage{epsfig}
	- \usepackage{graphicx}
	- \usepackage{rotating}
	- \usepackage{amssymb}
	- \usepackage{hyperref}
	- \usepackage[french]{babel}
	- \usepackage[utf8]{inputenc}
	- \usepackage[T1]{fontenc}
	- \usepackage{pslatex}
	- \usepackage{url}
	- \usepackage{color}
	- \usepackage{float}
	- \usepackage{parskip}
	- \usepackage{standalone}
	- \usepackage{longtable}
	- \usepackage{booktabs}
	- \usepackage{listings}
	- \usepackage{color}
	- \usepackage{caption}
	- \usepackage{float}
    - \usepackage{subcaption}
	- \definecolor{codegreen}{rgb}{0,0.6,0}
	- \definecolor{codered}{rgb}{0.6,0,0}
	- \definecolor{codeblue}{rgb}{0,0,0.6}
	- \definecolor{darkgreen}{rgb}{0.18,0.54,0.34}
	- \definecolor{codegray}{rgb}{0.5,0.5,0.5}
	- \definecolor{codepurple}{rgb}{0.58,0,0.82}
	- \definecolor{backcolour}{rgb}{0.95,0.95,0.92}
    - \usepackage{appendixnumberbeamer}
	- \usepackage{lipsum}
    - \newcommand{\backupbegin} {\newcounter{finalframe} \setcounter{finalframe}{\value{finalframe}}\stepcounter{finalframe} \stepcounter{finalframe}}
    - \newcommand{\backupend}{ \addtocounter{framenumber}{-1}} 
	- \usepackage{booktabs} 
	- \usepackage{dcolumn} 
	- \usepackage{threeparttable}
	- \usepackage{adjustbox} 

---

# Sommaire

\begin{exampleblock}{Présentation du sujet}
\end{exampleblock}

\begin{exampleblock}{\'Etat de l'art}
  \begin{itemize}
  	\item Techniques de défenses dynamiques
	\item Résilience
	\item Théorie des jeux
  \end{itemize}
\end{exampleblock}

\begin{exampleblock}{Travaux réalisés}
  \begin{itemize}
	\item Définition de l'architecture d'un véhicule
	\item Défense MTD basée sur la reconfiguration du réseau
	\item Stratégies de défenses optimales
  \end{itemize}
\end{exampleblock}

\begin{exampleblock}{Travaux futurs}
  \begin{itemize}
	\item Amélioration du modèle et prise en compte de la résilience
	\item Calcul de l'indice de résilience du véhicule
  \end{itemize}
\end{exampleblock}


# Présentation du sujet - Le contexte

\begin{columns}
    \begin{column}{0.75\textwidth}
        \begin{itemize}
            \item IoT de plus en plus présent dans la vie
            courante. \newline $\rightarrow$ fortement développé dans
            l'industrie automobile.
        \end{itemize}
    \end{column}
    \begin{column}{0.22\textwidth}
\begin{figure}[h]
    \centering
    \includegraphics[width=0.8\textwidth]{assets/Car.pdf}
    \label{idea1}
\end{figure}
    \end{column}
\end{columns}

  
- Cohabitation entre applications critiques (impliquant vies humaines)
  et applications non critiques (expérience de l'utilisateur).

- Nouvelles attaques non connues au moment de la conception du système
  qui apparaitront pendant la durée de vie du véhicule

- Objectif : Être capable de s'adapter à toutes formes d'attaques
  connues ou non. 
  \newline $\rightarrow$ Être le plus résilient possible.
  \newline $\rightarrow$ $\Uparrow$ Disponibilité ; $=$ Confidentialité et Intégrité


# Présentation du sujet - Trois Types d'Attaquants

- **Attaque physique** : Via diagnostique de la voiture. Objectif :
  Rajouter des fonctionnalités sur le véhicules pour lesquelles on a
  pas payé.

- **Attaque courte portée** : Via smartphone/laptop.. Objectif :
  Prendre le contrôle d'un véhicule proche, ou envoyer de fausses
  informations au véhicules alentours.

- **Attaque longue portée** : Via WiFi/4G. Objectif : Prendre le
  contrôle d'une flotte de véhicule.


\begin{figure}[h]
    \centering
    \includegraphics[width=0.5\textwidth]{assets/Car_Archi.jpg}
    \label{idea1}
\end{figure}


# Etat de l'Art - Techniques de Défenses Dynamiques

- Véhicules limités en puissance calcul et en ressources. \newline
  $\rightarrow$ Utilisation de méthodes de défense légère.

- Deux types de défenses dynamiques complémentaires applicables sur
  les véhicules : *Moving Target Defense* (MTD) et *Modes Dégradés*.

- Côté proactif : **MTD**\footnotemark : ralentir l'acquisition de
  connaissances sur le système par un attaquant.

- Côté réactif : **Modes Dégradés** : bloquer la progression d'un
  attaquant après les défenses percées. \newline Aide au retour du
  système dans état nominal.

\footnotetext[1]{Gui-linCaiet al. “Moving target defense : state of
the art and characteristics”. en. In :Frontiers of Information
Technology and Electronic Engineering17.11 (nov. 2016)}

# Etat de l'Art - Moving Target Defense

\begin{columns}
    \begin{column}{0.75\textwidth}
        \begin{itemize}
            \item Rendre dynamique différents aspects d'un système
				  \newline $\rightarrow$ Casser la relation asymétrique attaquant /
				  défenseur.
        \end{itemize}
    \end{column}
    \begin{column}{0.22\textwidth}
\begin{figure}[h]
    \centering
    \includegraphics[width=0.8\textwidth]{assets/MTD.jpg}
    \label{MTD}
\end{figure}
    \end{column}
\end{columns}


- Ralentir un attaquant dans l'acquisition de connaissances, la
 découverte de vulnérabilités et l'exploitation de failles

\begin{exampleblock}{Les MTD se divisent en 5 catégories \footnotemark : }
  \begin{itemize}
	\item Changer dynamiquement la représentation des données
	\item Utilisation dynamique d'applications
	\item Modification de l'environnement d'ex\'ecution
	\item Rendre dynamique la plateforme d'ex\'ecution
	\item Configuration dynamique du réseau
  \end{itemize}
\end{exampleblock}

\footnotetext{H.Okhraviet al.Survey of Cyber Moving Target Techniques
:en. Rapp. tech. Fort Belvoir, VA :Defense Technical Information
Center, sept. 2013.}

# Etat de l'Art - Efficacité des MTD Lors d'une Attaque

\begin{columns}
    \begin{column}{0.22\textwidth}
\begin{figure}[h]
    \centering
    \includegraphics[width=0.8\textwidth]{assets/hacker.jpg}
    \label{MTD}
\end{figure}
    \end{column}
\begin{column}{0.75\textwidth}
\begin{exampleblock}{Une attaque est divisée en 5 phases \footnotemark : }
  \begin{enumerate}
	\item Reconnaissance
	\item Accès
	\item Déploiement
	\item Lancement
	\item Persistence
  \end{enumerate}
\end{exampleblock}
    \end{column}
\end{columns}



\footnotetext{H.Okhraviet al. “Finding Focus in the Blur of
Moving-Target Techniques”. In :IEEE SecurityPrivacy12.2 (mar. 2014)}

\begin{table}
\begin{adjustbox}{width=\textwidth, totalheight=\textheight-2\baselineskip,keepaspectratio}
\begin{threeparttable}
\begin{tabular}{|l|l|l|l|l|l|} 
\hline
MTD/ Attack              & Reconnaissance & Accès        & Déploiement  & Lancement    & Persistence  \\ \hline
Réseau                   & $\checkmark$   &              &              & $\checkmark$ &              \\ \hline
Plateforme               &                & $\checkmark$ & $\checkmark$ &              & $\checkmark$ \\ \hline
Enviromenent d'Execution &                &              & $\checkmark$ & $\checkmark$ &              \\ \hline
Logiciel                 &                &              & $\checkmark$ & $\checkmark$ &              \\ \hline
Donées                   &                &              & $\checkmark$ & $\checkmark$ &              \\ \hline
\end{tabular}
\end{threeparttable}
\end{adjustbox}
\end{table}

# Etat de l'Art - Résilience

\begin{exampleblock}{Définition de la Résilience\footnotemark}
  \begin{itemize}
	\item The persistence of service delivery that can justifiably be
    trusted, when facing changes.
  \end{itemize}
\end{exampleblock}


\begin{exampleblock}{Notre Définition de la Résilience}
  \begin{itemize}
	\item Se défendre de manière proactive le plus longtemps possible
		  contre toutes formes d'attaques. Une fois ces défenses
		  tombées, revenir rapidement dans un \'etat de fonctionnement nominal grâce
		  à des mécanismes de défenses réactifs.
  \end{itemize}
\end{exampleblock}

\footnotetext{Laprie, Jean-Claude. “From Dependability to Resilience.”
International Conference on Dependable Systems and Networks (DSN 2008,
2008, 2.)}


- Exemple de méthodes visant à améliorer la résilience : \textit{Redondance, Obsfucation, Cryptographie, Monitorat, Isolation}.

# Etat de l'Art - Théorie des Jeux

\begin{columns}
    \begin{column}{0.75\textwidth}
        \begin{itemize}
            \item Problème décisionnel à résoudre ? \newline $\rightarrow$
			      Modélisation du problème grâce à la théorie des jeux \footnotemark \newline
				  $\rightarrow$ Analyse sur le modèle afin trouver une/des solution(s)
        \end{itemize}
    \end{column}
    \begin{column}{0.22\textwidth}
\begin{figure}[h]
    \centering
    \includegraphics[width=1\textwidth]{assets/game.jpg}
    \label{MTD}
\end{figure}
    \end{column}
\end{columns}


\footnotetext{Lin Chenet J.Leneutre. “A Game Theoretical Framework on
Intrusion Detection in Heteroge-neous Networks”. en. In :IEEE
Transactions on Information Forensics and Security4.2 (juin 2009)}

\begin{exampleblock}{Exemple : Recherche stratégies défenses optimales
en cas d'attaque.}
$\rightarrow$ Représentation interractions attaquant / defenseur avec
  modèle mathématique. \newline
$\rightarrow$ Permet l'observation de l'impact de la configuration
  système et méthodes défenses sur interactions attaquant /
  défenseur.
\end{exampleblock}


# Etat de l'Art - Analyse sur les Jeux

- La recherche des meilleures stratégies passe par l'analyse de
  plusieurs \'equilibres\footnotemark.

\footnotetext{Ziad Ismail et al.  “A Game Theoretical Model forOptimal
Distribution of Network Security Resources”.en. In: (2017)}

- **Equilibre de Nash** ; joueurs jouent simultanément. D\'etermination
  stratégies dont les deux joueurs ne devraient pas dévier seul.

- **Equilibre de Stackelberg** ; joueurs jouent chacun leur
  tour. Determination des meilleures stratégies permettant de limiter
  les gains du second joueur.

- **Minmax**. Permet de minimiser le reward maximum que l'autre joueur
  pourrait obtenir.


# Travaux Réalisés - Architecture Véhicule

\begin{figure}[h]
    \centering
    \includegraphics[width=1\textwidth]{assets/Car_complete_architecture.pdf}
    \label{idea1}
\end{figure}

# Travaux Réalisés - Défense MTD Basée sur la Reconfiguration du Réseau

- Méthode permettant cacher un véhicule dans un réseau. \newline
  $\rightarrow$ Changement régulier adresse IP + Limitation impact sur QoS.

- Publication article Workshop MTD associé ACM CCS de 2019 \footnotemark.

\footnotetext{Maxime Ayrault, Etienne Borde, Ulrich Kühne. “Run or
Hide ? Both ! A Method Based onIPv6 Address Switching to Escape While
Being Hidden”. In :Proceedings of the 6th ACMWorkshop on Moving Target
Defense - MTD’19.}


\begin{minipage}{0.38\textwidth}
\begin{figure}[]
    \centering
    \includegraphics[width=0.9\textwidth]{assets/net.pdf}
    \label{MTD}
\end{figure}
\end{minipage}
\begin{minipage}{0.6\textwidth}
\begin{exampleblock}{Actuellement : }
  \begin{itemize}
	\item Un véhicule = Une adresse IPv4 (appartenant 
    \`a la plage d'adresse du constructeur)
	\item Découverte de l'adresse $\rightarrow$ Collecte d'informations
    du système par attaquant possible.
  \end{itemize}
\end{exampleblock}

\end{minipage}



# Travaux Réalisés - Principe de notre Méthode


\begin{columns}
    \begin{column}{0.75\textwidth}
        \begin{itemize}
            \item Un véhicule = $N$ interfaces réseaux. \newline
				  $\rightarrow$ Plusieurs adresses IP par véhicule. \vspace{0.3cm} 
            \item Une seule adresse IP active à la fois. \newline (Active =
   				  Acceptant les messages entrant) \vspace{0.3cm}
            \item Rotation périodique de l'adresse IP active. \vspace{0.3cm}
            \item Renouvellement adresse IP après utilisation.\vspace{0.3cm}
            \item Utilisation \textit{MultiPath TCP} (MPTCP) \newline $\rightarrow$ Garantir une
				  qualité de service suffisante. 
        \end{itemize}
    \end{column}
    \begin{column}{0.22\textwidth}
\begin{figure}[h]
    \centering
    \includegraphics[width=0.9\textwidth]{assets/Car2.pdf}
    \label{MTD}
\end{figure}
    \end{column}
\end{columns}







# Travaux Réalisés - Différentes versions Méthode

- Version 1 : $N > 2$ ; Pas de renouvellement adresse après utilisation.

- Version 2 : $N > 2$ ; Renouvellement adresse après utilisation.

- Version 3 : $N = 2$ ; Renouvellement adresse après utilisation.

\begin{table}
\begin{tabular}{l | c | c | c | c }
 & Version 1 & Version 2 & Version 3 \\
\hline \hline
Coût interface & +++ & +++ &  + \\ 
Coût bande passante & +  & ++ & +++ \\
Risque d'attaque DoS & +++  & + & + \\
\end{tabular}
\end{table}



# Travaux Réalisés -  Exemple d'Utilisation de la Version 3

\begin{figure}[h]
    \centering
    \includegraphics[width=0.6\textwidth]{assets/exemple_ver3.pdf}
    \label{idea1}
\end{figure}


# Travaux Réalisés - Définition du Jeu

- 2 joueurs : Un attaquant (le hacker) - un défenseur (le
  système). \newline Nombre fini de mouvements définis.

- Une combinaison mouvement = une fonction reward par joueur. \newline
  \textit{$R_d$ : Reward Défenseur ; $R_a$ : Reward Attaquant}

- Choix des actions à réaliser \newline $\rightarrow$ Dépense d'un
  budget attribué à chaque joueur. \newline
  \textit{$P$ : Budget Défenseur ; $Q$ :  Budget Attaquant}
  

- Trouver les meilleures stratégies \newline $\rightarrow$ Objectif
  des deux joueurs = maximiser les rewards obtenus.


# Travaux Réalisés - Forme Normale Jeu

- Utilisation des budgets dans les actions : \newline \textit{$q_i$ :
  Se reconfigurer ; $q_i^{not}$ : ne rien faire ; $q_i^{deg}$ : Passer
  en mode dégradé ; \newline $p_i$ : attaquer ; $p_i^{not}$ : ne pas
  attaquer}

- Tableau représentant forme normale du jeu :

\begin{table}[]
\begin{tabular}{l|l|l|l|}
\cline{2-4}
                                                & Reconf ($q_i$)  & Rien ($q_i^{not}$) & Degradé ($q_i^{deg}$) \\ \hline
\multicolumn{1}{|l|}{Attaque ($p_i$)}           & $R^a_1 ; R^d_1$ & $R^a_2 ; R^d_2$    & $R^a_3 ; R^d_3$       \\ \hline
\multicolumn{1}{|l|}{Pas Attaque ($p_i^{not}$)} & $R^a_4 ; R^d_4$ & $R^a_5 ; R^d_5$    & $R^a_6 ; R^d_6$       \\ \hline
\end{tabular}
\end{table}

- Analyses de différents équilibres $\rightarrow$ determiner les
  meilleures stratégies.



# Futurs travaux

- Adapter le modèle au cas d'étude du véhicule.

- Prise en compte de la résilience dans le modèle du jeu.

- Calcul de l'indice de la résilience.

- Créer un modèle générique du jeu.
