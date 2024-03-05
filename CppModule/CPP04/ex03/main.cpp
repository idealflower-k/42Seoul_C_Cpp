#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"


int main()
{
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	ICharacter* me = new Character("me");
	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	ICharacter* bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);
	delete bob;
	delete me;
	delete src;
	
	system("leaks AMateria");
	return 0;
}

// int main(void) {

// 	IMateriaSource* src = new MateriaSource();

// 	src->learnMateria(new Ice());
// 	src->learnMateria(new Cure());

// 	ICharacter* me = new Character("me");

// 	AMateria* tmp;

// 	tmp = src->createMateria("ice");
// 	AMateria* tmp_tmp = tmp;
// 	me->equip(tmp);

// 	tmp = src->createMateria("cure");

// 	me->equip(tmp);

// 	ICharacter* bob = new Character("bob");
	
// 	std::cout << "AMateria use test" << std::endl;
// 	tmp_tmp->use(*bob);

// 	me->use(1, *bob);

// 	me->equip(src->createMateria("ice"));
	
// 	me->use(0, *bob);
// 	std::cout << "use unequip" << std::endl;
// 	me->unequip(0);
// 	me->use(0, *bob);

// 	me->use(1, *bob);

// 	delete tmp_tmp;
// 	delete bob;
// 	delete me;
// 	delete src;

// 	system("leaks AMateria");
// 	return (0);
// }

// int main(void) {
// 	Cure* a = new Cure();

// 	AMateria* b = a->clone();
// 	ICharacter* me = new Character("me");

// 	delete a;
// 	b->use(*me);

// 	delete b;
// 	delete me;

// 	system("leaks AMateria");
// }