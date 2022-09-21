library ieee;
use ieee.std_logic_1164.all;

entity half is
	port
	(
		a: in std_ulogic;
		b: in std_ulogic;
		o: out std_ulogic;
		bor: out std_ulogic
	);
end half;

architecture behave of half is
	begin
	o <= a xor b;
	bor <= not(a) and b;
end behave;
