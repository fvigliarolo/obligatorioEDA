#include "atributo_simple.h"
#include "define.h"
#include <string.h>

struct nodo_atributo_simple{
	char	valor;
	int		valor_secundario;
	atributo_simple sig;
};

