/* this file was automatically generated */
static char style_css[] =
"/* darkstat 3\n"
" *\n"
" * style.css: CSS stylesheet for web interface.\n"
" * copyright (c) 2006 Ben Stewart.\n"
" * colors broken in 2007 by Emil Mikulic.\n"
" *\n"
" * You may use, modify and redistribute this file under the terms of the\n"
" * GNU General Public License version 2. (see COPYING.GPL)\n"
" */\n"
"\n"
"body           { background-color: #fff; z-index: 0; }\n"
".content       { z-index: 1;\n"
"                 position: absolute; top:15px; left:10px; }\n"
"div.menu       { z-index: 2;\n"
"                 position: absolute; top:0; left:0;\n"
"                 width: 100%; background-color: #789;\n"
"                 border-bottom: 1px solid black;\n"
"                 font-size:11px; }\n"
"ul.menu        { list-style: none; margin:0; padding:2px 0 3px 0; }\n"
"ul.menu li     { list-style: none; display: inline; margin:0;\n"
"                 padding:2px 0 3px 0;\n"
"                 border-right:1px solid white; }\n"
"ul.menu li.label\n"
"               { padding-left:10px; padding-right:10px; color:#000;\n"
"                 text-shadow: 0px 1px 0px #9ab; }\n"
"ul.menu li a   { color: white; text-decoration: none;\n"
"                 text-shadow: 0px 1px 0px #456;\n"
"                 border-bottom: none; padding:2px 15px 3px 15px; }\n"
"ul.menu li a:hover\n"
"               { background-color: #9ab; }\n"
"h1, h2, h3, h4, h5, h6\n"
"               { margin-top:10px; margin-bottom:5px; color: #000000;\n"
"                 font-family: Arial, sans-serif; font-weight:bold; }\n"
".pageheader    { border-bottom: 2px dotted black; }\n"
"table          { border-collapse: collapse; }\n"
"td, th { border:1px solid #C0C0C0; padding:1px 5px 1px 5px; }\n"
"td.num { text-align:right; }\n"
"th { background-color:#EFEFEF; font-weight: bold;\n"
"     padding-top:2px; padding-bottom:2px; }\n"
"th a { color:black; border-bottom:1px dotted; }\n"
"tr.alt1 { background:#FFFFFF; }\n"
"tr.alt2 { background:#FAFAFA; }\n"
"tr.alt1:hover, tr.alt2:hover { background:#EFEFEF; }\n"
"body, td, th, p, input, textarea\n"
"               { font-family: Tahoma, Verdana, sans-serif;\n"
"                 font-size: small; }\n"
"tt             { font-family: Courier New, monospace;\n"
"                 font-size: small; }\n"
"a:hover        { border-bottom: 1px dotted #666; }\n"
"a              { text-decoration: none; color: #666; }\n"
"div.outergraph { float:left; margin-right:10px; margin-bottom:20px; }\n"
"div.graph      { border: 1px solid black; }\n"
"div.graphtitle { text-align:center; font-weight:bold; }\n"
"div.bar_in     { background: #678; }\n"
"div.bar_out    { background: #abc; }\n"
"\n"
"#graph_reload,#graph_autoreload { border:1px solid black;\n"
" padding:2px 10px 2px 10px; margin-left:5px; color:black; }\n"
"\n"
"#graph_reload:hover,#graph_autoreload:hover { background:#9ab; color:black; }\n"
"\n"
"div.legend table { margin-left:auto; margin-right:auto; /* center */\n"
"                   border:0; }\n"
"div.legend td { border:0; padding:0 0.2em 0 0.2em; font-size:11px;\n"
"                color:#444; }\n"
"div.legend td.dir { text-align:right; }\n"
"div.legend td.rate { text-align:right; white-space: nowrap; }\n";
static const size_t style_css_len = sizeof(style_css) - 1;
