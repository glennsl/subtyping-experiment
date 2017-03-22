module Dom = {
  type node_;
  type node 'ext = (node_, 'ext);
  type element_;
  type element 'ext = node (element_, 'ext);
  type htmlElement_;
  type htmlElement = element htmlElement_;
  type document_;
  type document 'ext = node (document_, 'ext);
  type htmlDocument_;
  type htmlDocument = document htmlDocument_;

  module Node = {
    external make : unit => node 'ext = "" [@@bs.val];

    external consume : node 'ext => unit = "" [@@bs.val];
  };

  module Element = {
    external make : unit => element 'ext = "" [@@bs.val];

    external consume : element 'ext => unit = "" [@@bs.val];

    external nextElement : element 'ext = "" [@@bs.send.pipe: element 'ext];
  };

  module HtmlElement = {
    external make : unit => htmlElement = "" [@@bs.val];

    external consume : htmlElement => unit = "" [@@bs.val];
  };
};

let node = Dom.Node.make ();
let _ = Dom.Node.consume node;

let _ = Dom.Element.consume node; /* this shouldn't typecheck */

let htmlElement = Dom.HtmlElement.make ();
let _ = Dom.Node.consume htmlElement;

let next = Dom.Element.nextElement htmlElement;

let _ = Dom.HtmlElement.consume next; /* this shouldn't typecheck */

let _ = Dom.Element.consume next;
