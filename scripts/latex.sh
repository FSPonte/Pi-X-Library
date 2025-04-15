echo -n "File name: "
read file_name
echo

pdflatex -output-directory="doc/" doc/$file_name

if [ -f "doc/texput.log" ]; then
    rm "doc/texput.log"
fi

if [ -f "doc/$file_name.aux" ]; then
    rm "doc/$file_name.aux"
fi

if [ -f "doc/$file_name.log" ]; then
    rm "doc/$file_name.log"
fi

if [ -f "doc/$file_name.toc" ]; then
    rm "doc/$file_name.toc"
fi
