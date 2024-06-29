// This code was used to navigate through a circular part of the maze.
// MontyMango
// https://edu.sphero.com/program/13114562

async function startProgram() {
	await roll(355, 133, 1.3);
	await roll(330, 110, 0.6);
	await roll(310, 121, 0.5);
	await roll(299, 110, 0.5);
	await roll(285, 118, 0.5);
	await roll(264, 111, 0.75);
	await roll(225, 116, 1);
	await delay(1);
	await roll(241, 145, 1);
	await delay(1);
	await roll(25, 104, 0);
}
