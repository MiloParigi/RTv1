typedef	struct	s_ppm
{
	char	*name;
	char	*data;
	int		width;
	int		height;
	int		hdrsize;
	int		ttlsize;
}				t_ppm;

void		mlx_to_ppm(t_mlx img, char *filename)
{
	int		index;
	int		fd;
	t_rgb	color;
	t_ppm	ppm;

	ppm.width = img.sizx;
	ppm.height = img.sizy;
	ppm_creator(&ppm);
	index = ppm.width * ppm.height;
	if (!(fd = open(filename, O_WRONLY | O_CREAT, 00777)))
		return ;
	while (index)
	{
		color = extract_color(&img, index % ppm.width, index / ppm.width);
		assign_val(&ppm, index--, color);
	}
	write(fd, ppm.data, ppm.ttlsize);
}