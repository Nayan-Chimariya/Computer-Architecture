library ieee;
use ieee.std_logic_1164.all;

entity fullAdder is
	port
	(
		a: in std_ulogic;
		b: in std_ulogic;
		cin: in std_ulogic;
		o: out std_ulogic;
		cout: out std_ulogic
	);
end fullAdder;

architecture behave of fullAdder is
	begin
	cout <= (a and b) or (a and cin) or (b and cin);
	o <= (a xor b) xor cin;
end behave;

