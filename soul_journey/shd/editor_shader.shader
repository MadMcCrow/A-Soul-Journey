shader_type spatial;
render_mode diffuse_burley;

uniform vec4 color : hint_color;

void vertex ()
{

}

void fragment()
{
	SPECULAR = 0.3;
	EMISSION = normalize(color).xyz;
	ALBEDO = color.xyz;
	ALPHA = 0.2;
}