library ieee;
use ieee.std_logic_1164.all;

entity halfSub_tb is
end  halfSub_tb;

architecture test of halfSub_tb is
	component half
	port
		(
			a: in std_ulogic;
			b: in std_ulogic;
			o: out std_ulogic;
			bor: out std_ulogic
		);
	end component;

	signal a,b,o,bor : std_ulogic;

	begin
		half_adder: half port map (a=>a, b=>b, o=>o, bor=>bor);
		
		process begin
		
			a<= 'X';
			b<= 'X';
		wait for 1 ns;
		
		a<= '0';
		b<= '0';
		wait for 1 ns;
		
		a<= '0';
		b<= '1';
		wait for 1 ns;
		
		a<= '1';
		b<= '0';
		wait for 1 ns;
		
		a<= '1';
		b<= '1';
		wait for 1 ns;
		
		assert false report "Reached the end";
		wait;
		end process;
	end test;
	
	
	
	