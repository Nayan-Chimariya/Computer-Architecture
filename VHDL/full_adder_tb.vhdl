library ieee;
use ieee.std_logic_1164.all;

entity fullAdder_tb is
end fullAdder_tb;

architecture test of fullAdder_tb is
	component fullAdder
	port
		(
			a: in std_ulogic;
			b: in std_ulogic;
			cin: in std_ulogic;
			o: out std_ulogic;
			cout: out std_ulogic
		);
	end component;

	signal a,b,cin,o,cout : std_ulogic;

	begin
		full_adder: fullAdder port map (a=>a, b=>b, cin=>cin, o=>o, cout=>cout);
		
		process begin
		
			a<= 'X';
			b<= 'X';
			cin<= 'X';
			
		wait for 1 ns;
		
		a<= '0';
		b<= '0';
		cin<= '0';
		wait for 1 ns;
		
		a<= '0';
		b<= '0';
		cin<= '1';
		
		wait for 1 ns;
		
		a<= '0';
		b<= '1';
		cin<= '0';
		
		wait for 1 ns;
		
		a<= '0';
		b<= '1';
		cin<= '1';
		
		wait for 1 ns;
		
		a<= '1';
		b<= '0';
		cin<= '0';
		
		wait for 1 ns;
		
		a<= '1';
		b<= '0';
		cin<= '1';
		
		wait for 1 ns;
		
		a<= '1';
		b<= '1';
		cin<= '0';
		
		wait for 1 ns;
		
		a<= '1';
		b<= '1';
		cin<= '1';
		
		wait for 1 ns;
		
		assert false report "Reached the end";
		wait;
		end process;
	end test;
	
	
	
	