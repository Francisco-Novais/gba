
//{{BLOCK(mapp)

//======================================================================
//
//	mapp, 512x256@4, 
//	+ palette 256 entries, not compressed
//	+ 31 tiles (t|f|p reduced) not compressed
//	+ regular map (in SBBs), not compressed, 64x32 
//	Total size: 512 + 992 + 4096 = 5600
//
//	Time-stamp: 2020-07-11, 22:04:12
//	Exported by Cearn's GBA Image Transmogrifier, v0.8.3
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

const unsigned int mappTiles[248] __attribute__((aligned(4)))=
{
	0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
	0x77777777,0x35375777,0x43475757,0x33727377,0x23347477,0x74547777,0x42352777,0x27555747,
	0x77774777,0x47744374,0x77455437,0x77473425,0x74553337,0x75775334,0x77534442,0x74743374,
	0x74554777,0x34237777,0x45757577,0x57574775,0x77447777,0x44777577,0x66667777,0x67777777,
	0x75534424,0x76373474,0x76745447,0x76657455,0x75664344,0x77766664,0x76766666,0x77777777,
	0x66666667,0x76655566,0x55553235,0x55777723,0x77755771,0x22211577,0x52222255,0x27777723,
	0x76666666,0x66777777,0x65577775,0x77775577,0x75557777,0x75577732,0x55555555,0x55777553,
	0x75777677,0x74475557,0x44424456,0x44444445,0x44344345,0x44444447,0x44444444,0x74544247,

	0x77775775,0x77777547,0x77747444,0x77775744,0x77775444,0x77557474,0x77774744,0x77755444,
	0x75555777,0x73223155,0x55311212,0x22177777,0x77773237,0x55555212,0x23321120,0x02211400,
	0x77777775,0x55566777,0x75777775,0x77777553,0x55557777,0x57777755,0x05555121,0x00612000,
	0x44444464,0x74447446,0x46444676,0x65755447,0x75557577,0x57775757,0x77777777,0x77777777,
	0x77577444,0x77777747,0x77757575,0x77777767,0x77775757,0x77777777,0x77777777,0x77777777,
	0x73217772,0x77744421,0x44432272,0x17777421,0x21444710,0x34432110,0x51771200,0x00220000,
	0x27732747,0x12473222,0x72144773,0x27227667,0x01441773,0x04435005,0x00320000,0x00000000,
	0x47744473,0x04444777,0x04477744,0x00474432,0x00444477,0x00004444,0x00000047,0x00000004,

	0x22112420,0x44324412,0x37732140,0x22777740,0x72212710,0x42122000,0x22710000,0x72100000,
	0x13565600,0x13565600,0x13565600,0x13565600,0x13565600,0x13565600,0x13565600,0x13565600,
	0x00654542,0x00654542,0x00654542,0x00654542,0x00654542,0x00654542,0x00654542,0x00654542,
	0x00000000,0x00000000,0x66666666,0x55555555,0x44444444,0x55555555,0x33333333,0x11111111,
	0x22222222,0x44444444,0x55555555,0x66666666,0x55555555,0x66666666,0x00000000,0x00000000,
	0x02222130,0x11111113,0x44444411,0x44462412,0x44466412,0x11124411,0x77744413,0x11124420,
	0x03222120,0x63311111,0x66444444,0x66624444,0x66664444,0x66445553,0x66447777,0x06445553,
	0x77744420,0x11124413,0x77744412,0x44444422,0x44462412,0x44466412,0x66666633,0x06666660,

	0x06447777,0x66445553,0x66447777,0x66444444,0x66634444,0x66664444,0x66666666,0x06666660,
	0x13555660,0x13555660,0x13555660,0x77777700,0x13555600,0x13555600,0x13555600,0x45666600,
	0x06554542,0x06554542,0x06554542,0x00777777,0x00654542,0x00654542,0x00654542,0x00665654,
	0x12661220,0x45544441,0x11211142,0x44444146,0x21114156,0x44414252,0x21424141,0x42414242,
	0x03226612,0x06444544,0x06431212,0x06464444,0x06664312,0x06464644,0x00464643,0x06464646,
	0x76424141,0x44434152,0x77764252,0x44444346,0x77777642,0x44464443,0x66606660,0x00000000,
	0x06664647,0x06464634,0x00464777,0x06463444,0x06477777,0x06346644,0x00660666,0x00000000,
};

const unsigned int mappMap[1024] __attribute__((aligned(4)))=
{
	0x00000000,0x00000000,0x00000000,0x30023001,0x00000000,0x00000000,0x00000000,0x00000000,
	0x30023001,0x00000000,0x00000000,0x00000000,0x30023001,0x00000000,0x30023001,0x00000000,
	0x00000000,0x00000000,0x00000000,0x30043003,0x00000000,0x00000000,0x00000000,0x00000000,
	0x30043003,0x00000000,0x00000000,0x00000000,0x30043003,0x00000000,0x30043003,0x00000000,
	0x00000000,0x00000000,0x00000000,0x00000000,0x30023001,0x30063005,0x30083007,0x30023001,
	0x30083007,0x30023001,0x30083007,0x00000000,0x30063005,0x30083007,0x30063005,0x30063005,
	0x00000000,0x00000000,0x00000000,0x00000000,0x30043003,0x300A3009,0x300C300B,0x30043003,
	0x300C300B,0x30043003,0x300C300B,0x00000000,0x300A3009,0x300C300B,0x300A3009,0x300E300D,

	0x38043803,0x30063005,0x30063005,0x30063005,0x300F3806,0x30093010,0x30063005,0x300F3806,
	0x30063005,0x30063005,0x300F3806,0x30063005,0x30063005,0x00000000,0x00000000,0x00000000,
	0x38023801,0x300A3009,0x300A3009,0x300A3009,0x0000300F,0x30100000,0x300A3009,0x0000300F,
	0x300E300D,0x300A3009,0x0000300F,0x300A3009,0x300A3009,0x00000000,0x00000000,0x00000000,
	0x380A3809,0x380A3809,0x380A3809,0x380A3809,0x00000000,0x00000000,0x00000000,0x00000000,
	0x00000000,0x30063005,0x00000000,0x30063005,0x30063005,0x00000000,0x00000000,0x00000000,
	0x38063805,0x38063805,0x38063805,0x38063805,0x00000000,0x00000000,0x00000000,0x00000000,
	0x00000000,0x300A3009,0x00000000,0x300E300D,0x300A3009,0x00000000,0x00000000,0x00000000,

	0x30123011,0x30023001,0x380A3809,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
	0x00000000,0x00000000,0x00000000,0x00000000,0x30063005,0x00000000,0x00000000,0x00000000,
	0x30123011,0x30043003,0x38063805,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
	0x00000000,0x00000000,0x00000000,0x00000000,0x300A3009,0x00000000,0x00000000,0x00000000,
	0x30123011,0x380A3809,0x380A3809,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
	0x00000000,0x00000000,0x00000000,0x00000000,0x30063005,0x00000000,0x380A3809,0x30133013,
	0x30123011,0x38063805,0x38063805,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
	0x00000000,0x00000000,0x00000000,0x00000000,0x300E300D,0x00000000,0x38063805,0x30143014,

	0x380A3809,0x380A3809,0x30123011,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
	0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x30123011,0x30023001,
	0x38063805,0x38063805,0x30123011,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
	0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x30123011,0x30043003,
	0x30023001,0x380A3809,0x380A3809,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
	0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x30123011,0x380A3809,
	0x30043003,0x38063805,0x38063805,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
	0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x30123011,0x38063805,

	0x380A3809,0x380A3809,0x30123011,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
	0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x380A3809,0x380A3809,
	0x38063805,0x38063805,0x30123011,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
	0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x38063805,0x38063805,
	0x30083007,0x380A3809,0x380A3809,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
	0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x380A3809,0x380A3809,
	0x300C300B,0x38063805,0x38063805,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
	0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x38063805,0x38063805,

	0x380A3809,0x30123011,0x380A3809,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
	0x30163015,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x30123011,
	0x38063805,0x30123011,0x38063805,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
	0x30183017,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x30123011,
	0x30023001,0x30123011,0x380A3809,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
	0x301A3019,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x380A3809,
	0x30043003,0x30123011,0x38063805,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
	0x30123011,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x38063805,

	0x380A3809,0x380A3809,0x380A3809,0x00000000,0x00000000,0x30163015,0x30163015,0x00000000,
	0x30123011,0x00000000,0x30163015,0x30163015,0x00000000,0x00000000,0x00000000,0x00000000,
	0x38063805,0x38063805,0x38063805,0x00000000,0x00000000,0x30183017,0x30183017,0x00000000,
	0x30123011,0x00000000,0x30183017,0x30183017,0x00000000,0x00000000,0x00000000,0x00000000,
	0x30023001,0x380A3809,0x380A3809,0x380E380D,0x380E380D,0x380E380D,0x380E380D,0x380E380D,
	0x380A3809,0x380A3809,0x380E380D,0x380E380D,0x380E380D,0x380A3809,0x380A3809,0x380E380D,
	0x30043003,0x38063805,0x38063805,0x38063805,0x38063805,0x38063805,0x38063805,0x38063805,
	0x38063805,0x38063805,0x38063805,0x38063805,0x38063805,0x38063805,0x38063805,0x38063805,

	0x00000000,0x00000000,0x00000000,0x380A3809,0x380A3809,0x30023001,0x30083007,0x380A3809,
	0x30023001,0x380A3809,0x380A3809,0x380A3809,0x30023001,0x30023001,0x380A3809,0x380A3809,
	0x00000000,0x00000000,0x00000000,0x38063805,0x38063805,0x30043003,0x300C300B,0x38063805,
	0x30043003,0x38063805,0x38063805,0x38063805,0x30043003,0x30043003,0x38063805,0x38063805,
	0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
	0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
	0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
	0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,

	0x00000000,0x30023001,0x00000000,0x30023001,0x30023001,0x30023001,0x00000000,0x30023001,
	0x30023001,0x30023001,0x00000000,0x00000000,0x30023001,0x30023001,0x30083007,0x00000000,
	0x00000000,0x30043003,0x00000000,0x30043003,0x30043003,0x30043003,0x00000000,0x30043003,
	0x30043003,0x30043003,0x00000000,0x00000000,0x30043003,0x30043003,0x300C300B,0x00000000,
	0x30083007,0x30063005,0x30063005,0x30063005,0x30023001,0x30023001,0x30083007,0x30063005,
	0x30083007,0x30063005,0x00000000,0x00000000,0x30063005,0x30023001,0x30083007,0x30063005,
	0x300C300B,0x300A3009,0x300A3009,0x300A3009,0x30043003,0x30043003,0x300C300B,0x300A3009,
	0x300C300B,0x300A3009,0x00000000,0x00000000,0x300A3009,0x30043003,0x300C300B,0x300A3009,

	0x00000000,0x00000000,0x00000000,0x00000000,0x30093010,0x30063005,0x30063005,0x30063005,
	0x30063005,0x30063005,0x30063005,0x30063005,0x30063005,0x30063005,0x30063005,0x30063005,
	0x00000000,0x00000000,0x00000000,0x00000000,0x30100000,0x300A3009,0x300A3009,0x300E300D,
	0x300A3009,0x300A3009,0x300A3009,0x300A3009,0x300A3009,0x300A3009,0x300E300D,0x300A3009,
	0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x30063005,0x00000000,
	0x30093010,0x300F3806,0x00000000,0x00000000,0x30093010,0x300F3806,0x00000000,0x30063005,
	0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x300A3009,0x00000000,
	0x30100000,0x0000300F,0x00000000,0x00000000,0x30100000,0x0000300F,0x00000000,0x300E300D,

	0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
	0x301C301B,0x00000000,0x00000000,0x00000000,0x00000000,0x301C301B,0x00000000,0x00000000,
	0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x301A3019,
	0x301E301D,0x00000000,0x00000000,0x00000000,0x00000000,0x301E301D,0x301A3019,0x00000000,
	0x30133013,0x380A3809,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x301C301B,
	0x380A3809,0x00000000,0x00000000,0x00000000,0x00000000,0x380A3809,0x301C301B,0x00000000,
	0x30143014,0x38063805,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x301E301D,
	0x38063805,0x00000000,0x00000000,0x00000000,0x00000000,0x38063805,0x301E301D,0x00000000,

	0x380A3809,0x30123011,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x380A3809,
	0x30123011,0x00000000,0x00000000,0x00000000,0x00000000,0x380A3809,0x30123011,0x00000000,
	0x38063805,0x30123011,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x38063805,
	0x30123011,0x00000000,0x00000000,0x00000000,0x00000000,0x38063805,0x30123011,0x00000000,
	0x30083007,0x30123011,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x30123011,
	0x30123011,0x00000000,0x00000000,0x00000000,0x00000000,0x30123011,0x30123011,0x00000000,
	0x300C300B,0x30123011,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x30123011,
	0x30123011,0x00000000,0x00000000,0x00000000,0x00000000,0x30123011,0x30123011,0x00000000,

	0x30133013,0x30133013,0x380A3809,0x00000000,0x00000000,0x00000000,0x00000000,0x380A3809,
	0x380A3809,0x00000000,0x00000000,0x00000000,0x00000000,0x380A3809,0x380A3809,0x00000000,
	0x30143014,0x30143014,0x38063805,0x00000000,0x00000000,0x00000000,0x00000000,0x38063805,
	0x38063805,0x00000000,0x00000000,0x00000000,0x00000000,0x38063805,0x38063805,0x00000000,
	0x30023001,0x30083007,0x30123011,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
	0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
	0x30043003,0x300C300B,0x30123011,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
	0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,

	0x380A3809,0x380A3809,0x380A3809,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
	0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
	0x38063805,0x38063805,0x38063805,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
	0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
	0x380A3809,0x380A3809,0x380A3809,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
	0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
	0x38063805,0x38063805,0x38063805,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
	0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,

	0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x30163015,
	0x30163015,0x30163015,0x00000000,0x00000000,0x30163015,0x30163015,0x30163015,0x00000000,
	0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x30183017,
	0x30183017,0x30183017,0x00000000,0x00000000,0x30183017,0x30183017,0x30183017,0x00000000,
	0x380E380D,0x380E380D,0x380E380D,0x380E380D,0x380E380D,0x380E380D,0x380E380D,0x30163015,
	0x30163015,0x30163015,0x30163015,0x30163015,0x30163015,0x30163015,0x30163015,0x380E380D,
	0x38063805,0x38063805,0x38063805,0x38063805,0x38063805,0x38063805,0x38063805,0x30183017,
	0x30183017,0x30183017,0x30183017,0x30183017,0x30183017,0x30183017,0x30183017,0x38063805,

	0x30083007,0x380A3809,0x380A3809,0x380A3809,0x380A3809,0x30023001,0x30023001,0x30083007,
	0x380A3809,0x380A3809,0x380A3809,0x30023001,0x380A3809,0x380A3809,0x30023001,0x380A3809,
	0x300C300B,0x38063805,0x38063805,0x38063805,0x38063805,0x30043003,0x30043003,0x300C300B,
	0x38063805,0x38063805,0x38063805,0x30043003,0x38063805,0x38063805,0x30043003,0x38063805,
	0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
	0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
	0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
	0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
};

const unsigned int mappPal[128] __attribute__((aligned(4)))=
{
	0x02DF1042,0x00AC01D7,0x41AD5A73,0x18632D08,0x48FB0BB1,0x00007FFF,0x44E57FFF,0x00007FFF,
	0x0BB11042,0x01451EA9,0x3DB35EBB,0x1486292E,0x4A526318,0x0000318C,0x02DF7FFF,0x0000001F,
	0x72BC1042,0x181648FB,0x0E141690,0x004100E5,0x246230C6,0x08001421,0x18407EFF,0x00007FFF,
	0x77381042,0x620976AE,0x41254D8B,0x20003500,0x416B5E52,0x1C6030E4,0x63186318,0x00007F9C,
	0x63181042,0x20E06318,0x2D211DA7,0x182028A0,0x25E926A9,0x04201542,0x008226A9,0x00002771,
	0x02BF1042,0x0015017F,0x42AE4F95,0x25233206,0x14C7152A,0x04021463,0x18400CA1,0x00007EB5,
	0x5EBA1042,0x3DB24E36,0x20CB2D2E,0x08021048,0x21D11A77,0x004224C7,0x63186B1C,0x0C007EB5,
	0x5D221042,0x18404463,0x1CA024C0,0x10401480,0x15D716DF,0x148614EE,0x63186318,0x080016DF,

	0x7FFF0000,0x6B5A77BD,0x7FFF6318,0x6B5A77BD,0x7FFF6318,0x6B5A77BD,0x7FFF6318,0x6B5A77BD,
	0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
	0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
	0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
	0x01080000,0x140503BD,0x21A843FF,0x4AD2579F,0x00BB3A4E,0x016B02B5,0x11040252,0x000D0074,
	0x7F5A0000,0x0216033B,0x7C1D0113,0x300A5814,0x26803BE0,0x52941580,0x210839CE,0x7D082484,
	0x7FFF0000,0x1D5519FF,0x53FF10AD,0x295F039E,0x000018DF,0x00000000,0x00000000,0x104A0000,
	0x72B20000,0x246171C7,0x7A8E1840,0x4D03660B,0x0F3F30A4,0x001F01BF,0x00000012,0x00000000,
};

//}}BLOCK(mapp)
