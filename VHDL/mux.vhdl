library ieee;
use ieee.std_logic_1164.all;

entity mux is
	port
	(
		a: in std_ulogic;
		b: in std_ulogic;
		c: in std_ulogic;
		d: in std_ulogic;
		s0: in std_ulogic;
		s1: in std_ulogic;
		res: out std_ulogic
	);
end mux;

architecture behave of mux is
begin
	process (a, b, c, d,s0,s1) is
	begin
		if(s0 = '0' and s1 = '0') then res <=a;
		elsif (s0 = '0' and s1 = '1') then res <=b;
		elsif(s0 = '1' and s1 = '0') then res <=c;
		else res <=d;
		end if;
	end process;
end behave;

