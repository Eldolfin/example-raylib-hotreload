with import <nixpkgs> { };

stdenv.mkDerivation {
  name = "Some random project";
  buildInputs = [ raylib ];
}
