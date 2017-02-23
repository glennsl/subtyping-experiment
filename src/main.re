module Dom = {
  type nodeish 'a;
  type node = nodeish unit;
  type elementish 'a;
  type element = nodeish (elementish unit);
  type htmlElementish;
  type htmlElement = nodeish (elementish htmlElementish);
  type documentish 'a;
  type document = nodeish (documentish unit);
  type htmlDocumentish;
  type htmlDocument = nodeish (documentish htmlDocumentish);


  module Node = {
    external make : unit => node = "" [@@bs.val];

    external consume : nodeish 'a => unit = "" [@@bs.val];
  };

  module Element = {
    external make : unit => element = "" [@@bs.val];

    external consume : elementish 'a => unit = "" [@@bs.val];
  };

  module HtmlElement = {
    external make : unit => htmlElement = "" [@@bs.val];

    external consume : htmlElementish => unit = "" [@@bs.val];
  };
};

let node = Dom.Node.make ();
let _ = Dom.Node.consume node;
/*let _ = Dom.Element.consume node;*/ /* this shouldn't typecheck */
let htmlElement = Dom.HtmlElement.make ();
let _ = Dom.Node.consume htmlElement;
