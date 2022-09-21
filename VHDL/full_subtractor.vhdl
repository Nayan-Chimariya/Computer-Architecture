library ieee;
use ieee.std_logic_1164.all;

entity fullSub is
	port
	(
		a: in std_ulogic;
		b: in std_ulogic;
		bin: in std_ulogic;
		d: out std_ulogic;
		bout: out std_ulogic
	);
end fullSub;

architecture behave of fullSub is
	begin
	bout <= (not a and bin) or (not a and b) or (b and bin);
	d <= (a xor b) xor bin;
end behave;

