# Dev Notes 

## `arch`, the main component

### Inheritance profile 

```
Ms... <- __core__::__atom__<Ms...> 
__core__::__atom__<> = Module <- ModList <- __core__::__arch__

Atom<Ms...> -> __core__::__atom__<__core__::__arch__<Ms...>, Ms...>
```

Idee : 
Atom est l'interface, une fois construit, il construit un `__core__::__atom__` propre (resolution d'heritage). 

``` 
template <class ...Ms> class Atom 
	construct_arch<Ms...>
	->  for M in Ms... : 
			if isinstance(M, Atom): 
				for Mi in M::__registry__: 
					append Mi to __arch__<Ms...>::__registry__
			elif isinstance(M, Module): 
				append M to __arch__<Ms...>::__registry__
		end for; 

	construct_atom<Ms...>
	-> 	fetch __arch__<Ms...>::__registry__
	->  __core__::__atom__ < list_to_va<__registry__> > 

------- 
exemple : 
Atom< m1, m2, m3 > = a1 
	=> __core__::__arch__<m1,m2,m3>::__registry__ = ModList<m1, m2, m3>
	=> __core__::__atom__<m1, m2, m3> -> m1, m2, m3
	=> __is_composed__<a1> doit retourner faux
			=> Constructs a first order Atom (__order__<a1> = 1)

Atom< a1, m2, m4 > = a2 
	// L'usage de a1 restreint l'héritage m2, le forcant a passer par a1 : 
	// 		comme m2 <- a1 <- __core__::__atom__<a1, m2, ...>
	// 			   ^-------------|
	// 		(Diamond of death)
	// par défaut, on construira : m2 <- a1 <- __core__::__atom__<a1, ...>
	=> __core__::__arch__<a1, m2, m4>::__registry__ = ModList<a1, m4> // m2 non présent dans le modlist
	=> __core__::__atom__<a1, m4> -> m4, (a1 -> m1, m2, m3) 

	=> __is_composed__<a2> doit retourner vrai 
			=> Constructs a second order Atom (__order__<a2> = 2)

Atom< __modules__<a1>, m2, m4> = a3 
	// L'utilisation de __modules__ permet d'extraire les modules composant a1
	=> __core__::__arch__<__modules__<a1>, m2, m4>::__registry__ = ModList<m1, m2, m3, m4> 
	=> __core__::__atom__<a1, m2, m4> -> m1, m2, m3, m4
	=> __is_composed__<a3> doit retourner faux
			=> Constructs a first order Atom (__order__<a3> = 1)

Atom<__modules__<a2>, m2> = a4 
	// a2 est d'ordre 2, __modules__récupère tout de meme les modules (ordre 0)
	=> __core__::__arch__<__modules__<a2>, m2>::__registry__ = ModList<m1, m2, m3, m4> 	
	=> __core__::__atom__<m1, m2, m3, m4> ->  m1, m2, m3, m4 

Atom< __bases__<a2>, m3, m5> = a5 
	// a2 est d'ordre 2, __bases__ récupère les bases de a5 (ordre 1)
	=> __core__::__arch__<__bases__<a2>, m3, m5>::__registry__ = ModList<a1, m5> // m3 est contenu dans les bases de a1
	=> __core__::__atom__<a1, m5> -> (a1 -> m1, m2, m3), m5
```

Basic flow : 
	-> Appel à `Atom<Ms ...>`
	-> Construction de `__core__::__arch__<Ms...>`, avec le bon `__registry__`, permettant de gérer les ordres 
	-> Construction de `__core__::__atom__<list_to_va<__core__::__arch__<Ms...>::__registry__>>`
		-> `Atom` contient l'information de `Ms...`
		-> `Ms...` permet de build une `__core__::__arch__`
		-> L'arch contient les infos pour construire un `__core__::__atom__` propre